#pragma once
#include "framework/Object.h"
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace ly
{
    class World;
    /*
        Actor class spawns a texture in the World using SFML
    */
    class Actor : public Object
    {
    private:
        World* mOwningWorld;
        bool mHasBeganPlay;

        sf::Sprite mSprite;
        shared<sf::Texture> mTexture;

        void CenterPivot();

    public:
        Actor(World* owningWorld, const std::string& texturePath = "");
        void BeginPlayInternal();
        virtual void BeginPlay();
        virtual void Tick(float deltaTime);
        void TickInternal(float deltaTime);
        virtual ~Actor();
        void SetTexture(const std::string& texturePath);
        void Render(sf::RenderWindow& window);

        void SetActorLocation(const sf::Vector2f& newLoc);
        void SetActorRotation(float newRot);
        void AddActorLocationOffset(const sf::Vector2f& offsetAmt);
        void AddActorRotationOffset(float offsetAmt);
        sf::Vector2f GetActorLocation() const;
        float GetActorRotation() const;
        sf::Vector2f GetActorForwardDirection() const;
        sf::Vector2f GetActorRightDirection() const;
        sf::Vector2u GetWindowSize();
        
    };
    
    
} // namespace ly
