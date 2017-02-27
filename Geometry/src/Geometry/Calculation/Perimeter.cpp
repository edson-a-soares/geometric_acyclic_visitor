#include "Geometry/Calculation/Perimeter.h"

namespace Geometry
{

    namespace Calculation
    {

        float Perimeter::calculate(Polygon::Triangle & triangle)
        {
            return (
                triangle.getSideA().getLength() +
                triangle.getSideB().getLength() +
                triangle.getSideC().getLength()
            );
        }

        float Perimeter::calculate(Polygon::Quadrilateral & quadrilateral)
        {
            return (
                quadrilateral.getSideA().getLength() +
                quadrilateral.getSideB().getLength() +
                quadrilateral.getSideC().getLength() +
                quadrilateral.getSideD().getLength()
            );
        }

    }

}
