#include "gtest/gtest.h"
#include "Geometry/Angle.h"
#include "Geometry/Segment.h"
#include "Geometry/Polygon/Square.h"
#include "Geometry/Exception/ClassInvariantViolationException.h"

using Geometry::Angle;
using Geometry::Segment;

TEST(SquareExceptionTestCase, SidesInvariantViolation) {

    ASSERT_THROW(
        Geometry::Polygon::Square square = Geometry::Polygon::Square(
            Angle(60), Angle(60), Angle(60), Angle(60),
            Segment(10), Segment(5), Segment(5), Segment(2)
        ),
        Geometry::Exception::ClassInvariantViolationException
    );

}

TEST(SquareExceptionTestCase, AnglesInvariantViolation) {

    ASSERT_THROW(
        Geometry::Polygon::Square square = Geometry::Polygon::Square(
            Angle(60), Angle(60), Angle(60), Angle(30),
            Segment(10), Segment(10), Segment(10), Segment(10)
        ),
        Geometry::Exception::ClassInvariantViolationException
    );

}
