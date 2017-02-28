#ifndef ACYCLIC_VISITOR_GEOMETRY_EXCEPTION_CLASS_INVARIANT_VIOLATION_EXCEPTION_H
#define ACYCLIC_VISITOR_GEOMETRY_EXCEPTION_CLASS_INVARIANT_VIOLATION_EXCEPTION_H

#include <string>
#include <stdexcept>

namespace Geometry
{

    namespace Exception
    {

        class ClassInvariantViolationException
            : public std::logic_error
        {
        public:
            ClassInvariantViolationException(const std::string &);

        };

    }

}

#endif
