#include <iostream>
#include "Geometry/Polygon/Rectangle.h"

namespace Geometry
{

    namespace Polygon
    {

        Rectangle::Rectangle (
            const Angle _angleAB,
            const Angle _angleBC,
            const Angle _angleCD,
            const Angle _angleDA,
            const Segment _sideA,
            const Segment _sideB,
            const Segment _sideC,
            const Segment _sideD
        ) : angleAB(_angleAB), angleBC(_angleBC), angleCD(_angleCD), angleDA(_angleDA),
            sideA(_sideA), sideB(_sideB), sideC(_sideC), sideD(_sideD)
        { }

        Rectangle::~Rectangle()
        { }

        void Rectangle::draw()
        {
            std::cout << "\nRectangle:" << std::endl;
        }

        Angle Rectangle::getAngleAB() const
        {
            return angleAB;
        }

        Angle Rectangle::getAngleBC() const
        {
            return angleBC;
        }

        Angle Rectangle::getAngleCD() const
        {
            return angleCD;
        }

        Angle Rectangle::getAngleDA() const
        {
            return angleDA;
        }

        Segment Rectangle::getSideA() const
        {
            return sideA;
        }

        Segment Rectangle::getSideB() const
        {
            return sideB;
        }

        Segment Rectangle::getSideC() const
        {
            return sideC;
        }

        Segment Rectangle::getSideD() const
        {
            return sideD;
        }

    }

}
