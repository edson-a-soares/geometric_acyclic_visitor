// Copyright 2017.
// All rights reserved.
//

#ifndef ACYCLIC_VISITOR_GEOMETRY_CALCULATION_RADIUS_H
#define ACYCLIC_VISITOR_GEOMETRY_CALCULATION_RADIUS_H

#include "Geometry/Circle.h"
#include "Geometry/Ellipse.h"

namespace Geometry
{

    namespace Calculation
    {

        class Radius
        {
        public:
            float calculate(Circle &);
            float calculate(Ellipse &);

        };

    }

}

#endif
