#include <iostream>
#include "Geometry/Circle.h"

namespace Geometry
{

    Circle::Circle(const float _diameter)
        : diameter(_diameter)
    { }

    Circle::~Circle()
    { }

    void Circle::draw()
    {
        std::cout << "\nCircle:" << std::endl;
    }

    float Circle::getDiameter() const
    {
        return diameter;
    }

}
