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
                this->TickInternal(_targetDeltaTime);
                this->RenderInternal();
            }

        }
    }

    void Application::TickInternal(float delta_time)
    {
        this->Tick(delta_time);
    }

    void Application::RenderInternal()
    {
        mWindow.clear();
        this->Render();
        mWindow.display();

    }

    void Application::Render()
    {
        sf::CircleShape rect{50};
        rect.setFillColor(sf::Color::Green);
        rect.setOrigin(25,25);
        rect.setPosition(mWindow.getSize().x/2.f, mWindow.getSize().y/2.f);
        mWindow.draw(rect);

    }

    void Application::Tick(float delta_time)
    {
        std::cout << "Ticking at Frane Rate: "<< 1.f/delta_time<< "\n";
    }

};
