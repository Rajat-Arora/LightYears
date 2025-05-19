#include "player/PlayerSpaceship.h"
#include "SFML/System.hpp"
#include "framework/MathUtility.h"
#include "weapon/BulletShooter.h"

namespace ly
{
    PlayerSpaceship::PlayerSpaceship(World* owningWorld, const std::string& path)
        : Spaceship{owningWorld, path},
        mMoveInput{sf::Vector2f{}},
        mSpeed{200.f},
        mShooter{new BulletShooter{this, 0.3f} }
    {

    }

    void PlayerSpaceship::Tick(float deltaTime)
    {
        Spaceship::Tick(deltaTime);
        HandleInput();
        ConsumeInput(deltaTime);

    }

    void PlayerSpaceship::Shoot()
    {
        if(mShooter)
        {
            mShooter->Shoot();
        }
    }


    void PlayerSpaceship::HandleInput()
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            mMoveInput.y = 1.f;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            mMoveInput.y = -1.f;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            mMoveInput.x = -1.f;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            mMoveInput.x = 1.f;
        }

        ClampInputOnEdge();
        NormalizeInput();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            Shoot();
        }
        
    }

    void PlayerSpaceship::NormalizeInput()
    {
        Normalize(mMoveInput);
    }

    void PlayerSpaceship::ClampInputOnEdge()
    {
        sf::Vector2f actorLoaction = GetActorLocation();
        if(actorLoaction.x < 0.f && mMoveInput.x == -1.f)
        {
            mMoveInput.x = 0.f;
        }

        if(actorLoaction.x > GetWindowSize().x && mMoveInput.x == 1.f)
        {
            mMoveInput.x = 0.f;
        }

        if(actorLoaction.y < 0.f && mMoveInput.y == -1.f)
        {
            mMoveInput.y = 0.f;
        }

        if(actorLoaction.y > GetWindowSize().y && mMoveInput.y == 1.f)
        {
            mMoveInput.y = 0.f;
        }
        
    }


    void PlayerSpaceship::ConsumeInput(float deltaTime)
    {
        sf::Vector2u windowSize = GetWindowSize();
        SetVelocity(mMoveInput * mSpeed);
        mMoveInput.x = mMoveInput.y = 0.0;
    }



    
} // namespace ly
