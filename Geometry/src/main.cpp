#include <iostream>

#include "Geometry/Angle.h"
#include "Geometry/Segment.h"

using Geometry::Angle;
using Geometry::Segment;

#include "Geometry/Circle.h"
#include "Geometry/Ellipse.h"

using Geometry::Circle;
using Geometry::Ellipse;

#include "Geometry/Polygon/Scalene.h"
#include "Geometry/Polygon/Isosceles.h"
#include "Geometry/Polygon/Equilateral.h"

using Geometry::Polygon::Scalene;
using Geometry::Polygon::Isosceles;
using Geometry::Polygon::Equilateral;

#include "Geometry/Polygon/Square.h"
#include "Geometry/Polygon/Rectangle.h"

using Geometry::Polygon::Square;
using Geometry::Polygon::Rectangle;

#include "Geometry/Measure/Area.h"
#include "Geometry/Measure/Radius.h"
#include "Geometry/Measure/Perimeter.h"
#include "Geometry/Measure/Circumference.h"

using Geometry::Measure::Area;
using Geometry::Measure::Radius;
using Geometry::Measure::Perimeter;
using Geometry::Measure::Circumference;

int main(int argc, char *argv[]) {

    std::cout << "Acyclic Visitor Shape's Measurements" << std::endl;

    // Available Measures
    Geometry::Calculation::Area areaCalculator;
    Geometry::Measure::Area area = Geometry::Measure::Area(areaCalculator);

    Geometry::Calculation::Radius radiusCalculator;
    Geometry::Measure::Radius radius = Geometry::Measure::Radius(radiusCalculator);

    Geometry::Calculation::Perimeter perimeterCalculator;
    Geometry::Measure::Perimeter perimeter = Geometry::Measure::Perimeter(perimeterCalculator);

    Geometry::Calculation::Circumference circumferenceCalculator;
    Geometry::Measure::Circumference circumference = Geometry::Measure::Circumference(circumferenceCalculator);

    // Circular Shapes
    Circle circle = Circle(50);

    circle.draw();
    circle.accept(area);
    circle.accept(radius);
    circle.accept(circumference);

    Ellipse ellipse = Ellipse(10, 10);

    ellipse.draw();
    ellipse.accept(area);
    ellipse.accept(radius);
    ellipse.accept(circumference);

    // Triangle Polygon available forms
    Scalene scalene = Scalene(
        Angle(30), Angle(60), Angle(90),
        Segment(9), Segment(11), Segment(5)
    );

    scalene.draw();
    scalene.accept(area);
    scalene.accept(radius);
    scalene.accept(perimeter);

    Isosceles isosceles = Isosceles(
        Angle(30), Angle(30), Angle(120),
        Segment(10), Segment(10), Segment(15)
    );

    isosceles.draw();
    isosceles.accept(area);
    isosceles.accept(radius);
    isosceles.accept(perimeter);

    Equilateral equilateral = Equilateral(
        Angle(60), Angle(60), Angle(60),
        Segment(8), Segment(8), Segment(8)
    );

    equilateral.draw();
    equilateral.accept(area);
    equilateral.accept(radius);
    equilateral.accept(perimeter);

    // Quadrilateral Polygon available forms
    Square square = Square(
        Angle(90), Angle(90), Angle(90), Angle(90),
        Segment(10), Segment(10), Segment(10), Segment(10)
    );

    square.draw();
    square.accept(area);
    square.accept(radius);
    square.accept(perimeter);

    Rectangle rectangle = Rectangle(
        Angle(90), Angle(90), Angle(90), Angle(90),
        Segment(20), Segment(10), Segment(20), Segment(10)
    );

    rectangle.draw();
    rectangle.accept(area);
    rectangle.accept(radius);
    rectangle.accept(perimeter);

    return 0;

}
