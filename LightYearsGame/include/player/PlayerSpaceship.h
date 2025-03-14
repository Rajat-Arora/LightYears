#pragma once
#include "spaceship/Spaceship.h"

namespace ly
{
    class PlayerSpaceship: public Spaceship
    {
    private:
        /* data */
        void HandleInput();
        sf::Vector2f mMoveInput;
        void ConsumeInput(float deltaTime);
        float mSpeed;
    public:
        PlayerSpaceship(World* owningWorld, const std::string& path = "SpaceShooterRedux/PNG/playerShip1_blue.png");
        // ~PlayerSpaceship();
        void SetSpeed(float newSpeed) { mSpeed = newSpeed; };
        float GetSpeed() const { return mSpeed; };
        virtual void Tick(float deltaTime) override;
    };
    
} // namespace ly
