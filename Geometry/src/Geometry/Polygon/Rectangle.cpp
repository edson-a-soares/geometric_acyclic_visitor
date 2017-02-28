#include <iostream>
#include "Geometry/Polygon/Rectangle.h"
#include "Geometry/Exception/ClassInvariantViolationException.h"

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
        {

            if ( !sidesInvariant() ) {
                throw Exception::ClassInvariantViolationException(
                    "A Rectangle must have at least two of its sides equal"
                );
            }

            if ( !anglesInvariant() ) {
                throw Exception::ClassInvariantViolationException(
                    "A Rectangle must have all its angles equal"
                    " and the sum of its internal angles must be equal 360 degrees"
                );
            }

        }

        Rectangle::~Rectangle()
        { }

        bool Rectangle::sidesInvariant()
        {
            bool result = true;
            if (getSideA().getLength() != getSideC().getLength()) result = false;
            if (getSideB().getLength() != getSideD().getLength()) result = false;
            return result;
        }

        bool Rectangle::anglesInvariant()
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
