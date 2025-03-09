#include "framework/World.h"
#include "framework/Application.h"
#include "framework/Actor.h"

ly::World::World(Application* owingApp):
    mOwningApp{owingApp},
    mBeganPlay{false},
    mActors{},
    mPendingActors{}
{

}

ly::World::~World()
{

}

void ly::World::BeginPlay()
{
    LOG("Begin Play from World base class");
}

void ly::World::BeginPlayInternal()
{
    if(!mBeganPlay)
    {
        mBeganPlay = true;
        this->BeginPlay();
    }
}

void ly::World::Tick(float deltaTime)
{
    LOG("World ticking at rate: ", 1.f/deltaTime);
}

void ly::World::TickInternal(float deltaTime)
{   
    for(shared<Actor> actor: mPendingActors)
    {
        mActors.emplace_back(actor);
        actor->BeginPlayInternal();
    }

    mPendingActors.clear();

    //This assures erasing of Actor object after the Tick is done once
    for(auto it=mActors.begin(); it != mActors.end();)
    {
        if(it->get()->IsPendingDestroy())
        {
            it = mActors.erase(it);
        }
        else
        {
            it->get()->TickInternal(deltaTime);
            ++it;
        }
    }
    this->Tick(deltaTime);
}

void ly::World::Render(sf::RenderWindow& window)
{
    for(auto& actor:mActors)
    {
        actor->Render(window);
    }
}
