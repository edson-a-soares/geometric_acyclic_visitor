#include <iostream>
#include "Geometry/Polygon/Square.h"

namespace Geometry
{

    namespace Polygon
    {

        Square::Square (
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

        Square::~Square()
        { }

        void Square::draw()
        {
            std::cout << "\nSquare:" << std::endl;
        }

        Angle Square::getAngleAB() const
        {
            return angleAB;
        }

        Angle Square::getAngleBC() const
        {
            return angleBC;
        }

        Angle Square::getAngleCD() const
        {
            return angleCD;
        }

        Angle Square::getAngleDA() const
        {
            return angleDA;
        }

        Segment Square::getSideA() const
        {
            return sideA;
        }

        Segment Square::getSideB() const
        {
            return sideB;
        }

        Segment Square::getSideC() const
        {
            return sideC;
        }

        Segment Square::getSideD() const
        {
            return sideD;
        }

    }

}
