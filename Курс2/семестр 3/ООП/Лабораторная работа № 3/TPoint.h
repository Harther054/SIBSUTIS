#pragma once
#include <SFML/Graphics.hpp>
class tPoint
{
private:
    float x, y;
    int R, G, B;
public:
    CircleShape circle;
    Vector2f velocity;
    void Random_Color();

    tPoint(float radius, float X, float Y);

};

