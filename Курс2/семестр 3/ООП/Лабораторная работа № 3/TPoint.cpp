#include "TPoint.h"

using namespace std;
using namespace sf;

void tPoint::Random_Color()
    {
        R = rand() % 255;
        G = rand() % 255;
        B = rand() % 255;
    }
 tPoint::tPoint(float radius, float X, float Y)
    {
        Random_Color();
        circle.setRadius(radius);
        circle.setPosition(X, Y);
        circle.setFillColor(Color(R, G, B));

        velocity.y = 0;
        velocity.x = 0;
    }