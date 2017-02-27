#include <cmath>
#include <iostream>
#include "Geometry/Measure/Area.h"

namespace Geometry
{

    namespace Measure
    {

        Area::Area(Calculation::Area & area)
            : calculator(area)
        { }

        void Area::visit(Circle & circle)
        {
            std::cout << "Area:          "
            << calculator.calculate(circle)
            << std::endl;
        }

        void Area::visit(Ellipse & ellipse)
        {
            std::cout << "Area:          "
            << calculator.calculate(ellipse)
            << std::endl;
        }

        void Area::visit(Polygon::Square & quadrilateral)
        {
            std::cout << "Area:      "
            << calculator.calculate(quadrilateral)
            << std::endl;
        }

        void Area::visit(Polygon::Rectangle & quadrilateral)
        {
            std::cout << "Area:      "
            << calculator.calculate(quadrilateral)
            << std::endl;
        }

        void Area::visit(Polygon::Scalene & triangle)
        {
            std::cout << "Area:      "
            << calculator.calculate(triangle)
            << std::endl;
        }

        void Area::visit(Polygon::Isosceles & triangle)
        {
            std::cout << "Area:      "
            << calculator.calculate(triangle)
            << std::endl;
        }

        void Area::visit(Polygon::Equilateral & triangle)
        {
            std::cout << "Area:      "
            << calculator.calculate(triangle)
            << std::endl;
        }

    }

}
