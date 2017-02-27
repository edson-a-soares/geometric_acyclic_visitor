#include <iostream>
#include "Geometry/Polygon/Scalene.h"

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
        ) : angleAB(_angleAB),
            angleBC(_angleBC),
            angleCA(_angleCA),
            sideA(_sideA),
            sideB(_sideB),
            sideC(_sideC)
        { }

        Scalene::~Scalene()
        { }

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
