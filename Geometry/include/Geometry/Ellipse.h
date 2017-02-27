// Copyright 2017.
// All rights reserved.
//

#ifndef ACYCLIC_VISITOR_GEOMETRY_ELLIPSE_H
#define ACYCLIC_VISITOR_GEOMETRY_ELLIPSE_H

#include "Geometry/Curved.h"
#include "Util/Measurable.h"

namespace Geometry
{

    class Ellipse :
        public Curved,
        public Util::Measurable
    {
    public:
        MEASURABLE()

        ~Ellipse();
        Ellipse(const float, const float);

        void draw();
        float getLongAxis() const;
        float getShortAxis() const;

    private:
        const float longAxis;
        const float shortAxis;

    };

}

#endif
