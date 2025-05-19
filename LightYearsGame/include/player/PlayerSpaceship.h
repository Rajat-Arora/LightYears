#pragma once
#include "spaceship/Spaceship.h"
#include "weapon/BulletShooter.h"


namespace ly
{
    class PlayerSpaceship: public Spaceship
    {
    private:
        /* data */
        void HandleInput();
        void NormalizeInput();
        void ClampInputOnEdge();
        sf::Vector2f mMoveInput;
        void ConsumeInput(float deltaTime);
        float mSpeed;
        unique<BulletShooter> mShooter;

    public:
        PlayerSpaceship(World* owningWorld, const std::string& path = "SpaceShooterRedux/PNG/playerShip1_blue.png");
        // ~PlayerSpaceship();
        void SetSpeed(float newSpeed) { mSpeed = newSpeed; };
        float GetSpeed() const { return mSpeed; };
        virtual void Tick(float deltaTime) override;
        virtual void Shoot() override;
    };
    
} // namespace ly
