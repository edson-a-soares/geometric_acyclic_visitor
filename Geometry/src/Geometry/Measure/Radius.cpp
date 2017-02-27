#include <iostream>
#include "Geometry/Measure/Radius.h"

namespace Geometry
{

    namespace Measure
    {

        Radius::Radius(Calculation::Radius & radius)
            : calculator(radius)
        { }

        void Radius::visit(Circle & circle)
        {
            std::cout << "Radius:        "
                      << calculator.calculate(circle)
                      << std::endl;
        }

        void Radius::visit(Ellipse & ellipse)
        {
            std::cout << "Radius:        "
                      << calculator.calculate(ellipse)
                      << std::endl;
        }

    }

}
