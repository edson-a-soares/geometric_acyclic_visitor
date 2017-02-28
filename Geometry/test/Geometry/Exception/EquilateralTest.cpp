#include "gtest/gtest.h"
#include "Geometry/Angle.h"
#include "Geometry/Segment.h"
#include "Geometry/Polygon/Equilateral.h"
#include "Geometry/Exception/ClassInvariantViolationException.h"

using Geometry::Angle;
using Geometry::Segment;

TEST(EquilateralExceptionTestCase, SidesInvariantViolation) {

    ASSERT_THROW(
        Geometry::Polygon::Equilateral triangle = Geometry::Polygon::Equilateral(
            Angle(60), Angle(60), Angle(60),
            Segment(10), Segment(5), Segment(5)
        ),
        Geometry::Exception::ClassInvariantViolationException
    );

}

TEST(EquilateralExceptionTestCase, AnglesInvariantViolation) {

    ASSERT_THROW(
        Geometry::Polygon::Equilateral triangle = Geometry::Polygon::Equilateral(
            Angle(30), Angle(60), Angle(60),
            Segment(5), Segment(5), Segment(5)
        ),
        Geometry::Exception::ClassInvariantViolationException
    );

}
