// Copyright 2017.
// All rights reserved.
//
// The visitable type.
//

#ifndef ACYCLIC_VISITOR_UTIL_VISITABLE_H
#define ACYCLIC_VISITOR_UTIL_VISITABLE_H

#include "Util/Measure.h"
#include "Util/Visitor.h"

namespace Util
{

    template <typename GenericType = void>
    class Visitable
    {
    public:
        virtual ~Visitable()
        { }

        typedef GenericType ReturnType;
        virtual GenericType accept(Visitor &) = 0;

    protected:
        template <class ConcreteType>
        static ReturnType acceptImplementation (ConcreteType & visited, Visitor & guest)
        {
            if ( Measure<ConcreteType> * visitor = dynamic_cast<Measure<ConcreteType> *>(&guest) ) {
                return visitor->visit(visited);
            }
            return ReturnType();
        }

    };

    #define MEASURABLE() \
        virtual ReturnType accept(::Util::Visitor & guest) \
        { return acceptImplementation(*this, guest); }

}

#endif
