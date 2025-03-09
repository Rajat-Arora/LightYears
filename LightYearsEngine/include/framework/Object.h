#pragma once

/*
    This class is intended as a Base class which helps the World to check if any object
    is required to be destroyed, if yes then the World could destroy it in the next Tick
*/
namespace ly
{
    class Object
    {
    private:
        /* data */
        bool mIsPendinfDestroy;
    public:
        Object(/* args */);
        virtual ~Object();

        void Destroy();
        bool IsPendingDestroy() const { return mIsPendinfDestroy;}
    };
    
    
} // namespace ly
