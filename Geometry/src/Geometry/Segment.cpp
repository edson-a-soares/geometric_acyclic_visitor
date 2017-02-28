#include "Geometry/Segment.h"

namespace Geometry
{

    Segment::Segment(const float length)
        : length(length)
    { }

    float Segment::getLength() const
    {
        return length;
    }

}
