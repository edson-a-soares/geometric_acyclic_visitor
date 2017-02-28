#include "gtest/gtest.h"
#include "Geometry/Angle.h"
#include "Geometry/Segment.h"
#include "Geometry/Polygon/Rectangle.h"
#include "Geometry/Exception/ClassInvariantViolationException.h"

using Geometry::Angle;
using Geometry::Segment;

TEST(RectangleExceptionTestCase, SidesInvariantViolation) {

    ASSERT_THROW(
        Geometry::Polygon::Rectangle rectangle = Geometry::Polygon::Rectangle(
            Angle(60), Angle(60), Angle(60), Angle(60),
            Segment(10), Segment(5), Segment(5), Segment(200)
        ),
        Geometry::Exception::ClassInvariantViolationException
    );

}

TEST(RectangleExceptionTestCase, AnglesInvariantViolation) {

    ASSERT_THROW(
        Geometry::Polygon::Rectangle rectangle = Geometry::Polygon::Rectangle(
            Angle(30), Angle(60), Angle(60), Angle(60),
            Segment(10), Segment(5), Segment(10), Segment(5)
        ),
        Geometry::Exception::ClassInvariantViolationException
    );

}
