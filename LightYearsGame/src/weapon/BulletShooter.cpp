#include "weapon/BulletShooter.h"

namespace ly
{
    BulletShooter::BulletShooter(Actor* owner, float cooldownTime)
        : Shooter(owner),
          mCoolDownClock{},
          mCoolDownTime{cooldownTime}
    {

    }
    
    bool BulletShooter::IsOnCoolDown() const
    {
        if(mCoolDownClock.getElapsedTime().asSeconds() > mCoolDownTime)
        {
            return false;
        }

        return true;
    }

    void BulletShooter::ShootImpl()
    {
        mCoolDownClock.restart();
    }
} // namespace ly
