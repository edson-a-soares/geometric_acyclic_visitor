#include <iostream>
#include "Geometry/Polygon/Equilateral.h"
#include "Geometry/Exception/ClassInvariantViolationException.h"

namespace Geometry
{

    namespace Polygon
    {

        Equilateral::Equilateral(
            const Angle _angleAB,
            const Angle _angleBC,
            const Angle _angleCA,
            const Segment _sideA,
            const Segment _sideB,
            const Segment _sideC
        ) : angleAB(_angleAB), angleBC(_angleBC), angleCA(_angleCA),
            sideA(_sideA), sideB(_sideB), sideC(_sideC)
        {

            if ( !sidesInvariant() ) {
                throw Exception::ClassInvariantViolationException(
                    "A Equilateral triangle must have all its sides equal"
                );
            }

            if ( !anglesInvariant() ) {
                throw Exception::ClassInvariantViolationException(
                    "A Equilateral triangle must have all its angles equal"
                    " and the sum of its internal angles must be equal 180 degrees"
                );
            }

        }

        Equilateral::~Equilateral()
        { }

        bool Equilateral::sidesInvariant()
        {
            bool result = true;
            if (getSideA().getLength() != getSideB().getLength()) result = false;
            if (getSideB().getLength() != getSideC().getLength()) result = false;
            return result;
        }

        bool Equilateral::anglesInvariant()
        {
            bool result     = true;
            float anglesSum = getAngleAB().getLength() +
                    getAngleBC().getLength() +
                    getAngleCA().getLength();

            if ( anglesSum != 180 ) result = false;

            if (getAngleAB().getLength() != getAngleBC().getLength()) result = false;
            if (getAngleBC().getLength() != getAngleCA().getLength()) result = false;
            return result;
        }

        void Equilateral::draw()
        {
            std::cout << "\nEquilateral Triangle:" << std::endl;
        }

        Angle Equilateral::getAngleAB() const
        {
            return angleAB;
        }

        Angle Equilateral::getAngleBC() const
        {
            return angleBC;
        }

        Angle Equilateral::getAngleCA() const
        {
            return angleCA;
        }

        Segment Equilateral::getSideA() const
        {
            return sideA;
        }

        Segment Equilateral::getSideB() const
        {
            return sideB;
        }

        Segment Equilateral::getSideC() const
        {
            return sideC;
        }

    }

}
