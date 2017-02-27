// Copyright 2017.
// All rights reserved.
//

#ifndef ACYCLIC_VISITOR_GEOMETRY_MEASURE_CIRCUMFERENCE_H
#define ACYCLIC_VISITOR_GEOMETRY_MEASURE_CIRCUMFERENCE_H

#include "Util/Measure.h"
#include "Util/Visitor.h"
#include "Geometry/Circle.h"
#include "Geometry/Ellipse.h"
#include "Geometry/Ellipse.h"
#include "Geometry/Calculation/Circumference.h"

namespace Geometry
{

    namespace Measure
    {

        class Circumference :
            public Util::Visitor,
            public Util::Measure<Circle>,
            public Util::Measure<Ellipse>
        {
        public:
            Circumference(Calculation::Circumference &);

            void visit(Circle &);
            void visit(Ellipse &);

        private:
            Calculation::Circumference & calculator;

        };

    }

}

#endif
