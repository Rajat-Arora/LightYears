#pragma once
#include "framework/Actor.h"

namespace ly
{

    class Spaceship: public Actor
    {
    private:
        sf::Vector2f mVelocity;
    public:
        Spaceship(World* owningWorld, const std::string& texturePath = "");
        virtual void Tick(float deltaTime) override;
        void SetVelocity(const sf::Vector2f& newVel);
        sf::Vector2f GetVelocity() const;

        // ~Spaceshi?p();
    };
    
    
    
} // namespace ly
