#include "gtest/gtest.h"
#include "Geometry/Angle.h"
#include "Geometry/Segment.h"
#include "Geometry/Polygon/Isosceles.h"
#include "Geometry/Exception/ClassInvariantViolationException.h"

using Geometry::Angle;
using Geometry::Segment;

TEST(IsoscelesExceptionTestCase, SidesInvariantViolation) {

    ASSERT_THROW(
        Geometry::Polygon::Isosceles triangle = Geometry::Polygon::Isosceles(
            Angle(30), Angle(60), Angle(60),
            Segment(5), Segment(5), Segment(5)
        ),
        Geometry::Exception::ClassInvariantViolationException
    );

}

TEST(IsoscelesExceptionTestCase, AnglesInvariantViolation) {

    ASSERT_THROW(
        Geometry::Polygon::Isosceles triangle = Geometry::Polygon::Isosceles(
            Angle(30), Angle(60), Angle(60),
            Segment(5), Segment(5), Segment(5)
        ),
        Geometry::Exception::ClassInvariantViolationException
    );

}
