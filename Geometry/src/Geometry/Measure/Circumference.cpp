#include <cmath>
#include <iostream>
#include "Geometry/Measure/Circumference.h"

namespace Geometry
{

    namespace Measure
    {

        Circumference::Circumference(Calculation::Circumference & circumference)
            : calculator(circumference)
        { }

        void Circumference::visit(Circle & circle)
        {
            std::cout << "Circumference: "
                      << calculator.calculate(circle)
                      << std::endl;
        }

        void Circumference::visit(Ellipse & ellipse)
        {
            std::cout << "Circumference: "
                      << calculator.calculate(ellipse)
                      << std::endl;
        }

    }

}
