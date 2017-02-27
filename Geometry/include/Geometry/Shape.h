// Copyright 2017.
// All rights reserved.
//

#ifndef ACYCLIC_VISITOR_GEOMETRY_SHAPE_H
#define ACYCLIC_VISITOR_GEOMETRY_SHAPE_H

namespace Geometry
{

    class Shape
    {
    public:
        virtual ~Shape()
        { };

        virtual void draw() = 0;

    };

}

#endif
