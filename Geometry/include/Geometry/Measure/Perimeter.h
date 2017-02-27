// Copyright 2017.
// All rights reserved.
//

#ifndef ACYCLIC_VISITOR_GEOMETRY_MEASURE_PERIMETER_H
#define ACYCLIC_VISITOR_GEOMETRY_MEASURE_PERIMETER_H

#include "Util/Measure.h"
#include "Util/Visitor.h"
#include "Geometry/Polygon/Square.h"
#include "Geometry/Polygon/Rectangle.h"
#include "Geometry/Polygon/Scalene.h"
#include "Geometry/Polygon/Isosceles.h"
#include "Geometry/Polygon/Equilateral.h"
#include "Geometry/Calculation/Perimeter.h"

namespace Geometry
{

    namespace Measure
    {

        class Perimeter :
            public Util::Visitor,
            public Util::Measure<Polygon::Square>,
            public Util::Measure<Polygon::Rectangle>,
            public Util::Measure<Polygon::Scalene>,
            public Util::Measure<Polygon::Isosceles>,
            public Util::Measure<Polygon::Equilateral>
        {
        public:
            Perimeter(Calculation::Perimeter &);

            void visit(Polygon::Square &);
            void visit(Polygon::Rectangle &);
            void visit(Polygon::Scalene &);
            void visit(Polygon::Isosceles &);
            void visit(Polygon::Equilateral &);

        private:
            Calculation::Perimeter & calculator;

        };

    }

}

#endif
