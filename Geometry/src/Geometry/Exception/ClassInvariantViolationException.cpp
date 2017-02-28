#include "Geometry/Exception/ClassInvariantViolationException.h"

namespace Geometry
{

    namespace Exception
    {

        ClassInvariantViolationException::ClassInvariantViolationException(const std::string & message)
            : logic_error(message)
        { }

    }

}
