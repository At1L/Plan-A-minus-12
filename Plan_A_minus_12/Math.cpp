#include "Math.h"

sf::Vector2f Math::NormalaizeVector(sf::Vector2f vector) 
{
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalaizedVector;
    normalaizedVector.x = vector.x / m;
    normalaizedVector.y = vector.y / m;
    return normalaizedVector;
}
