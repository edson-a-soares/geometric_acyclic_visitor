#include "gtest/gtest.h"
#include "Geometry/Angle.h"
#include "Geometry/Segment.h"
#include "Geometry/Polygon/Square.h"
#include "Geometry/Polygon/Scalene.h"
#include "Geometry/Calculation/Perimeter.h"

using Geometry::Angle;
using Geometry::Segment;

TEST(PerimeterTestCase, Triangle) {

    Geometry::Polygon::Scalene scalene = Geometry::Polygon::Scalene(
        Angle(30),  Angle(60),  Angle(90),
        Segment(7), Segment(9), Segment(13)
    );

    Geometry::Calculation::Perimeter perimeterCalculator;
    EXPECT_FLOAT_EQ(29, perimeterCalculator.calculate(scalene));

}

TEST(PerimeterTestCase, Quadrilateral) {

    Geometry::Polygon::Square square = Geometry::Polygon::Square(
        Angle(90),  Angle(90),  Angle(90),  Angle(90),
        Segment(5), Segment(5), Segment(5), Segment(5)
    );

    Geometry::Calculation::Perimeter perimeterCalculator;
    EXPECT_FLOAT_EQ(20, perimeterCalculator.calculate(square));

}
