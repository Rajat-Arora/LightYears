#include "framework/Application.h"
#include "framework/World.h"
#include "framework/AssetManager.h"

namespace ly
{
    Application::Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style)
        : mWindow{sf::VideoMode(windowWidth, windowHeight), title, style},
        mTargetFrameRate{60.f},
        mTickClock{},
        mCurrentWorld{nullptr},
        mCleanCycleClock{},
        mCleanCycleInterval{2.0}
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
        if(mCurrentWorld)
        {
            mCurrentWorld->BeginPlayInternal();
            mCurrentWorld->TickInternal(delta_time);
        }

        if(mCleanCycleClock.getElapsedTime().asSeconds() > mCleanCycleInterval)
        {
            mCleanCycleClock.restart();
            AssetManager::Get().CleanCycle();
        }
    }

    void Application::RenderInternal()
    {
        mWindow.clear();
        this->Render();
        mWindow.display();

    }

    void Application::Render()
    {
        // sf::CircleShape rect{50};
        // rect.setFillColor(sf::Color::Green);
        // rect.setOrigin(25,25);
        // rect.setPosition(mWindow.getSize().x/2.f, mWindow.getSize().y/2.f);
        // mWindow.draw(rect);

        if(mCurrentWorld)
        {
            mCurrentWorld->Render(mWindow);
        }

    }

    void Application::Tick(float delta_time)
    {
        LOG("Ticking at Frane Rate: ", 1.f/delta_time);
    }

};
