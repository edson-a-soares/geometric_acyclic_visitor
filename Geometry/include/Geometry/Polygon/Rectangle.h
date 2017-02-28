// Copyright 2017.
// All rights reserved.

#ifndef ACYCLIC_VISITOR_GEOMETRY_POLYGON_RECTANGLE_H
#define ACYCLIC_VISITOR_GEOMETRY_POLYGON_RECTANGLE_H

#include "Util/Measurable.h"
#include "Geometry/Polygon/Quadrilateral.h"

namespace Geometry
{

    namespace Polygon
    {

        class Rectangle
            : public Quadrilateral,
              public Util::Measurable
        {
        public:
            MEASURABLE()

            ~Rectangle();
            Rectangle(
                const Angle, const Angle, const Angle, const Angle,
                const Segment, const Segment, const Segment, const Segment
            );

            void draw();

            Angle getAngleAB() const;
            Angle getAngleBC() const;
            Angle getAngleCD() const;
            Angle getAngleDA() const;

            Segment getSideA() const;
            Segment getSideB() const;
            Segment getSideC() const;
            Segment getSideD() const;

        private:
            bool sidesInvariant();
            bool anglesInvariant();
            const Segment sideA, sideB, sideC, sideD;
            const Angle angleAB, angleBC, angleCD, angleDA;

        };

    }

}

#endif
