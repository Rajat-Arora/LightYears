#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"
namespace ly
{
    class World;
    class Application
    {
    public:
        Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style);
        void Run();

        //Loading a World, done by Client
        template<typename WorldType>
        weak<WorldType> LoadWorld()
        {
            shared<WorldType> newWorld{new WorldType{this} }; 
            mCurrentWorld = newWorld;
            return newWorld;
        }

    private:

        void TickInternal(float delta_time);
        void RenderInternal();
        virtual void Tick(float delta_time);
        void Render();
        
        //SFML Window
        sf::RenderWindow mWindow;
        float mTargetFrameRate;
        sf::Clock mTickClock;

        //Store current world, used to call World Internal Functions
        shared<World> mCurrentWorld;



    };
}