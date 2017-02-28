// Copyright 2017.
// All rights reserved.
//

#ifndef ACYCLIC_VISITOR_GEOMETRY_POLYGON_ISOSCELES_H
#define ACYCLIC_VISITOR_GEOMETRY_POLYGON_ISOSCELES_H

#include "Util/Measurable.h"
#include "Geometry/Polygon/Triangle.h"

namespace Geometry
{

    namespace Polygon
    {

        class Isosceles :
            public Triangle,
            public Util::Measurable
        {
        public:
            MEASURABLE()

            ~Isosceles();
            Isosceles(
                const Angle, const Angle, const Angle,
                const Segment, const Segment, const Segment
            );

            void draw();

            Angle getAngleAB() const;
            Angle getAngleBC() const;
            Angle getAngleCA() const;

            Segment getSideA() const;
            Segment getSideB() const;
            Segment getSideC() const;

        private:
            bool sidesInvariant();
            bool anglesInvariant();
            const Segment sideA, sideB, sideC;
            const Angle angleAB, angleBC, angleCA;

        };

    }

}

#endif
