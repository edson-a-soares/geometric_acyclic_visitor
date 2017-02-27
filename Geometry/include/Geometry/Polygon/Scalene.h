#ifndef ACYCLIC_VISITOR_GEOMETRY_POLYGON_SCALENE_H
#define ACYCLIC_VISITOR_GEOMETRY_POLYGON_SCALENE_H

#include "Util/Measurable.h"
#include "Geometry/Polygon/Triangle.h"

namespace Geometry
{

    namespace Polygon
    {

        class Scalene :
            public Triangle,
            public Util::Measurable
        {
        public:
            MEASURABLE()

            ~Scalene();
            Scalene(
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
            const Segment sideA, sideB, sideC;
            const Angle angleAB, angleBC, angleCA;

        };

    }

}

#endif
