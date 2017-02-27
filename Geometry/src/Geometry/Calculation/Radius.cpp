#include "Geometry/Calculation/Radius.h"

namespace Geometry
{

    namespace Calculation
    {

        float Radius::calculate(Circle & circle)
        {
            return circle.getDiameter() / 2.0;
        }

        float Radius::calculate(Ellipse & ellipse)
        {
            return ( (2.0 * ellipse.getLongAxis() + ellipse.getShortAxis()) / 3.0 );
        }

    }

}
