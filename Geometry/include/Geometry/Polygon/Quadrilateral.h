// Copyright 2017.
// All rights reserved.
//

#ifndef ACYCLIC_VISITOR_GEOMETRY_POLYGON_QUADRILATERAL_H
#define ACYCLIC_VISITOR_GEOMETRY_POLYGON_QUADRILATERAL_H

#include "Geometry/Shape.h"
#include "Geometry/Angle.h"
#include "Geometry/Segment.h"

namespace Geometry
{

    namespace Polygon
    {

        class Quadrilateral : public Shape
        {
        public:
            virtual ~Quadrilateral()
            { };

            virtual Angle getAngleAB() const = 0;
            virtual Angle getAngleBC() const = 0;
            virtual Angle getAngleCD() const = 0;
            virtual Angle getAngleDA() const = 0;

            virtual Segment getSideA() const = 0;
            virtual Segment getSideB() const = 0;
            virtual Segment getSideC() const = 0;
            virtual Segment getSideD() const = 0;

        };

    }

}

#endif
