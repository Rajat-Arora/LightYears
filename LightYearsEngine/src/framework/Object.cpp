#include "framework/Object.h"
#include "framework/Core.h"

namespace ly
{
    Object::Object()
        : mIsPendinfDestroy{false}
    {

    }

    Object::~Object()
    {
        LOG("Object Destroyed");
    }
    
    void Object::Destroy()
    {
        mIsPendinfDestroy = true;
    }
    
} // namespace ly

