#pragma once
#include "weapon/Shooter.h"
#include "SFML/System.hpp"


namespace ly
{
    class BulletShooter : public Shooter
    {
    private:
       sf::Clock mCoolDownClock;
       float mCoolDownTime;
       virtual void ShootImpl() override;
    public:
        BulletShooter(Actor* owner, float cooldownTime=1.f);
        virtual bool IsOnCoolDown() const override;
    
    };
    
} // namespace ly
