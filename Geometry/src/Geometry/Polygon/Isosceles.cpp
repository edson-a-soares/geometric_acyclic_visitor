#include <iostream>
#include "Geometry/Polygon/Isosceles.h"

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
        ) : angleAB(_angleAB),
            angleBC(_angleBC),
            angleCA(_angleCA),
            sideA(_sideA),
            sideB(_sideB),
            sideC(_sideC)
        { }

        Isosceles::~Isosceles()
        { }

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
