// Copyright 2017.
// All rights reserved.
//

#ifndef ACYCLIC_VISITOR_GEOMETRY_MEASURE_AREA_H
#define ACYCLIC_VISITOR_GEOMETRY_MEASURE_AREA_H

#include "Util/Measure.h"
#include "Util/Visitor.h"
#include "Geometry/Circle.h"
#include "Geometry/Ellipse.h"
#include "Geometry/Polygon/Square.h"
#include "Geometry/Polygon/Scalene.h"
#include "Geometry/Calculation/Area.h"
#include "Geometry/Polygon/Rectangle.h"
#include "Geometry/Polygon/Isosceles.h"
#include "Geometry/Polygon/Equilateral.h"

namespace Geometry
{

    namespace Measure
    {

        class Area :
            public Util::Visitor,
            public Util::Measure<Circle>,
            public Util::Measure<Ellipse>,
            public Util::Measure<Polygon::Square>,
            public Util::Measure<Polygon::Rectangle>,
            public Util::Measure<Polygon::Scalene>,
            public Util::Measure<Polygon::Isosceles>,
            public Util::Measure<Polygon::Equilateral>
        {
        public:
            Area(Calculation::Area &);

            void visit(Circle &);
            void visit(Ellipse &);
            void visit(Polygon::Square &);
            void visit(Polygon::Rectangle &);
            void visit(Polygon::Scalene &);
            void visit(Polygon::Isosceles &);
            void visit(Polygon::Equilateral &);

        private:
            Calculation::Area & calculator;

        };

    }

}

#endif
