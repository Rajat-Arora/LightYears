#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
namespace ly
{
    class Application
    {
    public:
        Application();
        void Run();

    private:

        void Tick(float delta_time);
        void Render();
        
        //SFML Window
        sf::RenderWindow mWindow;
        float mTargetFrameRate;
        sf::Clock mTickClock;


    };
}