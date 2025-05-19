#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

namespace ly
{
    
    sf::Vector2f RotationToVector(float rotation);
    float DegreesToRadians(float degrees);
    float RadiansToDegrees(float radians);

    template<typename T>
    float GetVectorLength(sf::Vector2<T>& vector)
    {
        return std::sqrt(vector.x * vector.x + vector.y * vector.y);
    }

    template<typename T>
    sf::Vector2<T>& ScaleVector(sf::Vector2<T>& vectorToScale, float amt)
    {
        vectorToScale.x *=amt;
        vectorToScale.y *=amt;
        return vectorToScale;
    }

    template<typename T>
    sf::Vector2<T>& Normalize(sf::Vector2<T>& vector)
    {
        float vectorLength = GetVectorLength(vector);
        if(vectorLength == 0.f) return vector;

        ScaleVector(vector, 1.f/vectorLength);

        return vector;
    }
    


} // namespace ly
