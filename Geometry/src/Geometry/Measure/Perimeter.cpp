#include <cmath>
#include <iostream>
#include "Geometry/Measure/Perimeter.h"

namespace Geometry
{

    namespace Measure
    {

        Perimeter::Perimeter(Calculation::Perimeter & perimeter)
            : calculator(perimeter)
        { }

        void Perimeter::visit(Polygon::Square & quadrilateral)
        {
            std::cout << "Perimeter: "
                      << calculator.calculate(quadrilateral)
                      << std::endl;
        }

        void Perimeter::visit(Polygon::Rectangle & quadrilateral)
        {
            std::cout << "Perimeter: "
                      << calculator.calculate(quadrilateral)
                      << std::endl;
        }

        void Perimeter::visit(Polygon::Scalene & triangle)
        {
            std::cout << "Perimeter: "
                      << calculator.calculate(triangle)
                      << std::endl;
        }

        void Perimeter::visit(Polygon::Isosceles & triangle)
        {
            std::cout << "Perimeter: "
                      << calculator.calculate(triangle)
                      << std::endl;
        }

        void Perimeter::visit(Polygon::Equilateral & triangle)
        {
            std::cout << "Perimeter: "
                      << calculator.calculate(triangle)
                      << std::endl;
        }

    }

}
