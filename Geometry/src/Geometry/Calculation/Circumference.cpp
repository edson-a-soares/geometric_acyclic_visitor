#include <cmath>
#include "Util/Math.h"
#include "Geometry/Calculation/Circumference.h"

namespace Geometry
{

    namespace Calculation
    {

        float Circumference::calculate(Circle & circle)
        {
            return (Util::Math::PI * circle.getDiameter());
        }

        float Circumference::calculate(Ellipse & ellipse)
        {
            float squareRoot = std::sqrt(
                (std::pow(ellipse.getLongAxis(), 2) + std::pow(ellipse.getShortAxis(), 2)) / 2
            );
            return 2 * Util::Math::PI * squareRoot;
        }

    }

}
