#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "config.h"
#include "player/PlayerSpaceship.h"
#include "framework/AssetManager.h"
std::unique_ptr<ly::Application> GetApplication()
{
    return std::make_unique<ly::GameApplication>();
}

namespace ly
{
    GameApplication::GameApplication()
        : Application(600, 980, "Light Years", sf::Style::Titlebar | sf::Style::Close)
    {
        AssetManager::Get().SetAssetRootDirectoryPath(GetResourceDir());
        weak<World> newWorld = LoadWorld<World>();
        // newWorld.lock()->SpawnActor<Actor>();
        mActorToDestroy = newWorld.lock()->SpawnActor<PlayerSpaceship>();
        // mActorToDestroy.lock()->SetTexture("SpaceShooterRedux/PNG/playerShip1_blue.png");
        mActorToDestroy.lock()->SetActorLocation(sf::Vector2f(300.f, 490.f));
        mActorToDestroy.lock()->SetActorRotation(360.f);
        // mActorToDestroy.lock()->SetVelocity(sf::Vector2f{0.f, -200.f});
        counter = 0;
    }

    void GameApplication::Tick(float delta_time)
    {
        // counter += delta_time;
        // if(counter > 2.f)
        // {
        //     if(!mActorToDestroy.expired())
        //     {
        //         mActorToDestroy.lock()->Destroy();
        //     }
        // }

    }

    
} // namespace ly

