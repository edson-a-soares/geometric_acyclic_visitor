#include <cmath>
#include <iostream>
#include "Util/Math.h"
#include "Geometry/Calculation/Area.h"

namespace Geometry
{

    namespace Calculation
    {

        float Area::calculate(Circle & circle)
        {
            float radius = circle.getDiameter() / 2.0;
            return (Util::Math::PI * std::pow(radius, 2));
        }

        float Area::calculate(Ellipse & ellipse)
        {
            return (ellipse.getLongAxis() * ellipse.getShortAxis() * Util::Math::PI);
        }

        float Area::calculate(Polygon::Triangle & triangle)
        {
            float semiperimeter = (
                triangle.getSideA().getLength() +
                triangle.getSideB().getLength() +
                triangle.getSideC().getLength()) / 2.0;

            float productSemiperimeterSidesSubtraction =
                (semiperimeter - triangle.getSideA().getLength()) *
                (semiperimeter - triangle.getSideB().getLength()) *
                (semiperimeter - triangle.getSideC().getLength());

            return std::sqrt(semiperimeter * productSemiperimeterSidesSubtraction);
        }

        float Area::calculate(Polygon::Quadrilateral & quadrilateral)
        {
            float semiperimeter = (
                quadrilateral.getSideA().getLength() +
                quadrilateral.getSideB().getLength() +
                quadrilateral.getSideC().getLength() +
                quadrilateral.getSideD().getLength()
            ) / 2.0;

            float productSemiperimeterSidesSubtraction =
                (semiperimeter - quadrilateral.getSideA().getLength()) *
                (semiperimeter - quadrilateral.getSideB().getLength()) *
                (semiperimeter - quadrilateral.getSideC().getLength()) *
                (semiperimeter - quadrilateral.getSideD().getLength());

            float sidesProduct =
                quadrilateral.getSideA().getLength() *
                quadrilateral.getSideB().getLength() *
                quadrilateral.getSideC().getLength() *
                quadrilateral.getSideD().getLength();

            double anglesCosseno = std::cos(
                ((quadrilateral.getAngleAB().getLength() + quadrilateral.getAngleCD().getLength()) / 2)
                    * Util::Math::PI / 180.0
            );

            return std::sqrt(productSemiperimeterSidesSubtraction - sidesProduct * std::pow(anglesCosseno, 2));
        }

    }

}
