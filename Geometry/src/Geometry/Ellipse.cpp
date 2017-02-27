#include <iostream>
#include "Geometry/Ellipse.h"

namespace Geometry
{

    Ellipse::Ellipse(const float _longAxis, const float _shortAxis)
        : longAxis(_longAxis),
          shortAxis(_shortAxis)
    { }

    Ellipse::~Ellipse()
    { }

    void Ellipse::draw()
    {
        std::cout << "\nEllipse:" << std::endl;
    }

    float Ellipse::getLongAxis() const
    {
        return longAxis;
    }

    float Ellipse::getShortAxis() const
    {
        return shortAxis;
    }

}
