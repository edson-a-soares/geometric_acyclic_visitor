// Copyright 2017.
// All rights reserved.
//

#ifndef ACYCLIC_VISITOR_GEOMETRY_CALCULATION_PERIMETER_H
#define ACYCLIC_VISITOR_GEOMETRY_CALCULATION_PERIMETER_H

#include "Geometry/Polygon/Triangle.h"
#include "Geometry/Polygon/Quadrilateral.h"

namespace Geometry
{

    namespace Calculation
    {

        class Perimeter
        {
        public:
            float calculate(Polygon::Triangle &);
            float calculate(Polygon::Quadrilateral &);

        };

    }

}

#endif
