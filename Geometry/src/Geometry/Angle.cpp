#include "Geometry/Angle.h"

namespace Geometry
{

    Angle::Angle(const float length)
        : length(length)
    { }

    float Angle::getLength() const
    {
        return length;
    }

}
