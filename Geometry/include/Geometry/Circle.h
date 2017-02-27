// Copyright 2017.
// All rights reserved.
//

#ifndef ACYCLIC_VISITOR_GEOMETRY_CIRCLE_H
#define ACYCLIC_VISITOR_GEOMETRY_CIRCLE_H

#include "Geometry/Curved.h"
#include "Util/Measurable.h"

namespace Geometry
{

    class Circle :
        public Curved,
        public Util::Measurable
    {
    public:
        MEASURABLE()

        ~Circle();
        Circle(const float);

        void draw();
        float getDiameter() const;

    private:
        const float diameter;

    };

}

#endif
