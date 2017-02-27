// Copyright 2017.
// All rights reserved.
//
// The Visitor type.
// Likely Concrete Visitors: Perimeter, Area, Radius
//

#ifndef ACYCLIC_VISITOR_UTIL_MEASURE_H
#define ACYCLIC_VISITOR_UTIL_MEASURE_H

namespace Util
{

    template <class ConcreteType, typename GenericType = void>
    class Measure
    {
    public:
        typedef GenericType ReturnType;
        virtual ReturnType visit(ConcreteType &) = 0;

    };

}

#endif
