#include "gtest/gtest.h"
#include "Geometry/Angle.h"
#include "Geometry/Segment.h"
#include "Geometry/Polygon/Scalene.h"
#include "Geometry/Exception/ClassInvariantViolationException.h"

using Geometry::Angle;
using Geometry::Segment;

TEST(ScaleneExceptionTestCase, SidesInvariantViolation) {

    ASSERT_THROW(
        Geometry::Polygon::Scalene triangle = Geometry::Polygon::Scalene(
            Angle(30), Angle(60), Angle(90),
            Segment(5), Segment(15), Segment(15)
        ),
        Geometry::Exception::ClassInvariantViolationException
    );

}

TEST(ScaleneExceptionTestCase, AnglesInvariantViolation) {

    ASSERT_THROW(
        Geometry::Polygon::Scalene triangle = Geometry::Polygon::Scalene(
            Angle(30), Angle(60), Angle(60),
            Segment(5), Segment(15), Segment(15)
        ),
        Geometry::Exception::ClassInvariantViolationException
    );

}
