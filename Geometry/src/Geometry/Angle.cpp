#include "Geometry/Angle.h"

namespace Geometry
{

    Angle::Angle(int length) : length(length)
    { }

    int Angle::getLength() const
    {
        return length;
    }

    void Angle::setLength(int _length)
    {
        length = _length;
    }

}
