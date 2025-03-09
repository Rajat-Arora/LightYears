#pragma once
#include"framework/Core.h"
#include <SFML/Graphics.hpp>

namespace ly
{   
    class Actor;
    class Application;
    //Base class for World, used to load world in Application. Client could define a World.
    class World
    {
    public:
        World(Application* owingApp);
        virtual ~World();
        void BeginPlayInternal();
        void TickInternal(float delta_time);

        void Render(sf::RenderWindow& window);

        template<typename ActorType>
        weak<ActorType> SpawnActor()
        {
            shared<ActorType> newActor{ new ActorType{this} };
            mPendingActors.push_back(newActor);
            return newActor;
        }

    private:
        shared<Application> mOwningApp;
        bool mBeganPlay;
        void Tick(float delta_time);
        void BeginPlay();

        List<shared<Actor>> mActors;
        List<shared<Actor>> mPendingActors;
    };

} // namespace ly

