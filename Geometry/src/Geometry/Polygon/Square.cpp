#include <iostream>
#include "Geometry/Polygon/Square.h"
#include "Geometry/Exception/ClassInvariantViolationException.h"

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
        {

            if ( !sidesInvariant() ) {
                throw Exception::ClassInvariantViolationException(
                    "A Square must have all its sides equal"
                );
            }

            if ( !anglesInvariant() ) {
                throw Exception::ClassInvariantViolationException(
                    "A Square must have all its angles equal"
                    " and the sum of its internal angles must be equal 360 degrees"
                );
            }

        }

        Square::~Square()
        { }

        bool Square::sidesInvariant()
        {
            bool result = true;
            if (getSideA().getLength() != getSideB().getLength()) result = false;
            if (getSideB().getLength() != getSideC().getLength()) result = false;
            if (getSideC().getLength() != getSideD().getLength()) result = false;
            return result;
        }

        bool Square::anglesInvariant()
        {
            bool result     = true;
            float anglesSum = getAngleAB().getLength() +
                              getAngleBC().getLength() +
                              getAngleCD().getLength() +
                              getAngleDA().getLength();

            if ( anglesSum != 360 ) result = false;

            if (getAngleAB().getLength() != getAngleBC().getLength()) result = false;
            if (getAngleBC().getLength() != getAngleCD().getLength()) result = false;
            if (getAngleCD().getLength() != getAngleDA().getLength()) result = false;
            return result;
        }

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
