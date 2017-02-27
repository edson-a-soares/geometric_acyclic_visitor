#include <iostream>
#include "Geometry/Polygon/Equilateral.h"

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
        ) : angleAB(_angleAB),
            angleBC(_angleBC),
            angleCA(_angleCA),
            sideA(_sideA),
            sideB(_sideB),
            sideC(_sideC)
        { }

        Equilateral::~Equilateral()
        { }

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
