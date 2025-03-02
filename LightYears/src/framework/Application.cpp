#include "framework/Application.h"

namespace ly
{
    Application::Application()
        : mWindow{sf::VideoMode(1024, 1440), "Light Years"},
        mTargetFrameRate{60.f},
        mTickClock{}
    {

    }

    void Application::Run()
    {
        mTickClock.restart();
        float _targetDeltaTime = 1.f / mTargetFrameRate;
        float _elapsedTime = 0.f;

        while(mWindow.isOpen())
        {
            sf::Event window_event;
            while(mWindow.pollEvent(window_event))
            {
                if(window_event.type == sf::Event::Closed)
                {
                    mWindow.close();
                }
            }

            _elapsedTime += mTickClock.restart().asSeconds();
            
            if(_elapsedTime > _targetDeltaTime)
            {
                _elapsedTime-=_targetDeltaTime;
                this->Tick(_targetDeltaTime);
            }

        }
    }

    void Application::Tick(float delta_time)
    {
        std::cout << "Ticking at Frane Rate: "<< 1.f/delta_time<< "\n";
    }

    void Application::Render()
    {
        
    }

}