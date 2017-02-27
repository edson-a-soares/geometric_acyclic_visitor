#include "gtest/gtest.h"
#include "Geometry/Circle.h"
#include "Geometry/Ellipse.h"
#include "Geometry/Calculation/Radius.h"

TEST(RadiusTestCase, CircleShape) {

    Geometry::Circle circle = Geometry::Circle(300);

    Geometry::Calculation::Radius radiusCalculator;
    ASSERT_NEAR(150.0, radiusCalculator.calculate(circle), 0.1);

}

TEST(RadiusTestCase, EllipseShape) {

    Geometry::Ellipse ellipse = Geometry::Ellipse(5, 15);

    Geometry::Calculation::Radius radiusCalculator;
    ASSERT_NEAR(8.33, radiusCalculator.calculate(ellipse), 0.1);

}
