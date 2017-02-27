// Copyright 2017.
// All rights reserved.
//

#ifndef ACYCLIC_VISITOR_GEOMETRY_MEASURE_RADIUS_H
#define ACYCLIC_VISITOR_GEOMETRY_MEASURE_RADIUS_H

#include "Util/Measure.h"
#include "Util/Visitor.h"
#include "Geometry/Circle.h"
#include "Geometry/Ellipse.h"
#include "Geometry/Calculation/Radius.h"

namespace Geometry
{

    namespace Measure
    {

        class Radius :
            public Util::Visitor,
            public Util::Measure<Circle>,
            public Util::Measure<Ellipse>
        {
        public:
            Radius(Calculation::Radius &);

            void visit(Circle &);
            void visit(Ellipse &);

        private:
            Calculation::Radius & calculator;

        };

    }

}

#endif
