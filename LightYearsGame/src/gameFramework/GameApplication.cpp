#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "config.h"

std::unique_ptr<ly::Application> GetApplication()
{
    return std::make_unique<ly::GameApplication>();
}

namespace ly
{
    GameApplication::GameApplication()
        : Application(600, 980, "Light Years", sf::Style::Titlebar | sf::Style::Close)
    {
        weak<World> newWorld = LoadWorld<World>();
        newWorld.lock()->SpawnActor<Actor>();
        mActorToDestroy = newWorld.lock()->SpawnActor<Actor>();
        mActorToDestroy.lock()->SetTexture(GetResourceDir() + "SpaceShooterRedux/PNG/playerShip1_blue.png");
        counter = 0;
    }

    void GameApplication::Tick(float delta_time)
    {
        counter += delta_time;
        if(counter > 2.f)
        {
            if(!mActorToDestroy.expired())
            {
                mActorToDestroy.lock()->Destroy();
            }
        }

    }

    
} // namespace ly

