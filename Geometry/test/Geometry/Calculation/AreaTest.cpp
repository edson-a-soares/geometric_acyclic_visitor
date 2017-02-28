#include "gtest/gtest.h"
#include "Geometry/Angle.h"
#include "Geometry/Circle.h"
#include "Geometry/Ellipse.h"
#include "Geometry/Segment.h"
#include "Geometry/Polygon/Square.h"
#include "Geometry/Polygon/Scalene.h"
#include "Geometry/Calculation/Area.h"
#include "Geometry/Polygon/Rectangle.h"
#include "Geometry/Polygon/Isosceles.h"
#include "Geometry/Polygon/Equilateral.h"

using Geometry::Angle;
using Geometry::Segment;

TEST(AreaTestCase, CircleShape) {

    Geometry::Circle circle = Geometry::Circle(100);

    Geometry::Calculation::Area areaCalculator;
    ASSERT_NEAR(7853.75, areaCalculator.calculate(circle), 0.1);

}

TEST(AreaTestCase, EllipseShape) {

    Geometry::Ellipse ellipse = Geometry::Ellipse(15.0, 25.0);

    Geometry::Calculation::Area areaCalculator;
    ASSERT_NEAR(1178.09, areaCalculator.calculate(ellipse), 0.1);

}

TEST(AreaTestCase, ScaleneTriangle) {

    Geometry::Polygon::Scalene scalene = Geometry::Polygon::Scalene(
        Angle(30),  Angle(60), Angle(90),
        Segment(18), Segment(24), Segment(30)
    );

    Geometry::Calculation::Area areaCalculator;
    ASSERT_NEAR(216, areaCalculator.calculate(scalene), 0.1);

}

TEST(AreaTestCase, IsoscelesTriangle) {

    Geometry::Polygon::Isosceles isosceles = Geometry::Polygon::Isosceles(
        Angle(30),  Angle(30), Angle(120),
        Segment(10), Segment(10), Segment(12)
    );

    Geometry::Calculation::Area areaCalculator;
    ASSERT_NEAR(48, areaCalculator.calculate(isosceles), 0.1);

}

TEST(AreaTestCase, EquilateralTriangle) {

    Geometry::Polygon::Equilateral equilateral = Geometry::Polygon::Equilateral(
        Angle(60),  Angle(60), Angle(60),
        Segment(10), Segment(10), Segment(10)
    );

    Geometry::Calculation::Area areaCalculator;
    ASSERT_NEAR(43.30, areaCalculator.calculate(equilateral), 0.1);

}

TEST(AreaTestCase, Square) {

    Geometry::Polygon::Square square = Geometry::Polygon::Square(
        Angle(90),  Angle(90),  Angle(90),  Angle(90),
        Segment(5), Segment(5), Segment(5), Segment(5)
    );

    Geometry::Calculation::Area areaCalculator;
    ASSERT_NEAR(25, areaCalculator.calculate(square), 0.1);

}

TEST(AreaTestCase, Rectangle) {

    Geometry::Polygon::Rectangle rectangle = Geometry::Polygon::Rectangle(
        Angle(90),  Angle(90),  Angle(90),  Angle(90),
        Segment(25), Segment(50), Segment(25), Segment(50)
    );

    Geometry::Calculation::Area areaCalculator;
    ASSERT_NEAR(1250, areaCalculator.calculate(rectangle), 0.1);

}
