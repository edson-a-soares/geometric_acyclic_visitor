#include "gtest/gtest.h"
#include "Geometry/Circle.h"
#include "Geometry/Ellipse.h"
#include "Geometry/Calculation/Circumference.h"

TEST(CircumferenceTestCase, CircleShape) {

    Geometry::Circle circle = Geometry::Circle(100);

    Geometry::Calculation::Circumference circumferenceCalculator;
    ASSERT_NEAR(314.159, circumferenceCalculator.calculate(circle), 0.1);

}

TEST(CircumferenceTestCase, EllipseShape) {

    Geometry::Ellipse ellipse = Geometry::Ellipse(50.0, 75.0);

    Geometry::Calculation::Circumference circumferenceCalculator;
    ASSERT_NEAR(400.47, circumferenceCalculator.calculate(ellipse), 0.1);

}
