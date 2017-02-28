#include <iostream>
#include "Geometry/Polygon/Isosceles.h"
#include "Geometry/Exception/ClassInvariantViolationException.h"

namespace Geometry
{

    namespace Polygon
    {

        Isosceles::Isosceles(
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
                    "A Isosceles triangle must have at least two of its sides equal"
                    " and it must follow the triangle inequality theorem"
                );
            }

            if ( !anglesInvariant() ) {
                throw Exception::ClassInvariantViolationException(
                    "A Isosceles triangle must have at least two of its angles equal"
                    " and the sum of its internal angles must be equal 180 degrees"
                );
            }

        }

        Isosceles::~Isosceles()
        { }

        bool Isosceles::sidesInvariant()
        {
            bool result = true;

            // It check out if the triangle has two sides equal
            if (getSideA().getLength() == getSideB().getLength() &&
                getSideB().getLength() == getSideC().getLength()) result = false;

            if (getSideA().getLength() != getSideB().getLength() &&
                getSideB().getLength() != getSideC().getLength()) result = false;

            /*
             * The triangle inequality theorem states that:
             *      "The sum of the lengths of any two sides of a
             *      triangle is greater than the length of the third side."
             *
             *      A + B > C
             *      B + C > A
             *      A + C > B
             */
            if ((getSideA().getLength() + getSideB().getLength()) < getSideC().getLength()) result = false;
            if ((getSideB().getLength() + getSideC().getLength()) < getSideA().getLength()) result = false;
            if ((getSideA().getLength() + getSideC().getLength()) < getSideB().getLength()) result = false;

            return result;
        }

        bool Isosceles::anglesInvariant()
        {
            bool result     = true;
            float anglesSum = getAngleAB().getLength() +
                              getAngleBC().getLength() +
                              getAngleCA().getLength();

            if ( anglesSum != 180 ) result = false;

            if (getAngleAB().getLength() == getAngleBC().getLength() &&
                getAngleBC().getLength() == getAngleCA().getLength()) result = false;

            if (getAngleAB().getLength() != getAngleBC().getLength() &&
                getAngleBC().getLength() != getAngleCA().getLength()) result = false;

            return result;
        }

        void Isosceles::draw()
        {
            std::cout << "\nIsosceles Triangle:" << std::endl;
        }

        Angle Isosceles::getAngleAB() const
        {
            return angleAB;
        }

        Angle Isosceles::getAngleBC() const
        {
            return angleBC;
        }

        Angle Isosceles::getAngleCA() const
        {
            return angleCA;
        }

        Segment Isosceles::getSideA() const
        {
            return sideA;
        }

        Segment Isosceles::getSideB() const
        {
            return sideB;
        }

        Segment Isosceles::getSideC() const
        {
            return sideC;
        }

    }

}
