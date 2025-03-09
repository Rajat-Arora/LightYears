#pragma once
#include "framework/Object.h"
#include <SFML/Graphics.hpp>
#include "framework/Core.h"
#include "framework/AssetManager.h"

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

    public:
        Actor(World* owningWorld, const std::string& texturePath = "");
        void BeginPlayInternal();
        virtual void BeginPlay();
        virtual void Tick(float deltaTime);
        void TickInternal(float deltaTime);
        virtual ~Actor();
        void SetTexture(const std::string& texturePath);
        void Render(sf::RenderWindow& window);
    };
    
    
} // namespace ly
