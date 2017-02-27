#include "Geometry/Segment.h"

namespace Geometry
{

    Segment::Segment(int length)
        : length(length)
    { }

    int Segment::getLength() const
    {
        return length;
    }

    void Segment::setLength(int _length)
    {
        length = _length;
    }

}
