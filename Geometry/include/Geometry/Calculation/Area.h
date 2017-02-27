// Copyright 2017.
// All rights reserved.
//

#ifndef ACYCLIC_VISITOR_GEOMETRY_CALCULATION_AREA_H
#define ACYCLIC_VISITOR_GEOMETRY_CALCULATION_AREA_H

#include "Geometry/Circle.h"
#include "Geometry/Ellipse.h"
#include "Geometry/Polygon/Triangle.h"
#include "Geometry/Polygon/Quadrilateral.h"

namespace Geometry
{

    namespace Calculation
    {

        class Area
        {
        public:
            float calculate(Circle &);
            float calculate(Ellipse &);
            float calculate(Polygon::Triangle &);
            float calculate(Polygon::Quadrilateral &);

        };

    }

}

#endif
