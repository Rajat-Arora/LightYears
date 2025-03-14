#pragma once
#include <framework/Application.h>
#include <framework/Core.h>
#include <memory>

namespace ly
{
    class Spaceship;
    class Actor;
    class GameApplication: public Application
    {
    public:
        GameApplication();
        virtual void Tick(float delta_time) override;
    
    private:
        float counter;
        weak<Spaceship> mActorToDestroy;
    };

}
