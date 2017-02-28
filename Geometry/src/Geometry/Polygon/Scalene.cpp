#include <iostream>
#include "Geometry/Polygon/Scalene.h"
#include "Geometry/Exception/ClassInvariantViolationException.h"

namespace Geometry
{

    namespace Polygon
    {

        Scalene::Scalene(
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
                    "A Scalene triangle must have all its sides different"
                    " and it must follow the triangle inequality theorem"
                );
            }

            if ( !anglesInvariant() ) {
                throw Exception::ClassInvariantViolationException(
                    "A Scalene triangle must have all its angles different"
                    " and the sum of its internal angles must be equal 180 degrees"
                );
            }

        }

        Scalene::~Scalene()
        { }

        bool Scalene::sidesInvariant()
        {
            bool result = true;

            if (getSideA().getLength() == getSideB().getLength()) result = false;
            if (getSideB().getLength() == getSideC().getLength()) result = false;
            if (getSideC().getLength() == getSideA().getLength()) result = false;

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

        bool Scalene::anglesInvariant()
        {
            bool result     = true;
            float anglesSum = getAngleAB().getLength() +
                              getAngleBC().getLength() +
                              getAngleCA().getLength();

            if ( anglesSum != 180 ) result = false;

            if (getAngleAB().getLength() == getAngleBC().getLength()) result = false;
            if (getAngleBC().getLength() == getAngleCA().getLength()) result = false;
            return result;
        }

        void Scalene::draw()
        {
            std::cout << "\nScalene Triangle:" << std::endl;
        }

        Angle Scalene::getAngleAB() const
        {
            return angleAB;
        }

        Angle Scalene::getAngleBC() const
        {
            return angleBC;
        }

        Angle Scalene::getAngleCA() const
        {
            return angleCA;
        }

        Segment Scalene::getSideA() const
        {
            return sideA;
        }

        Segment Scalene::getSideB() const
        {
            return sideB;
        }

        Segment Scalene::getSideC() const
        {
            return sideC;
        }

    }

}
