# Acyclic Visitor, a geometrical model #

It describes how to use different geometric shapes to understand how [Acyclic Visitor](http://wiki.c2.com/?AcyclicVisitor) 
can help us to avoid the most inherent limitations and drawbacks of its variation [Visitor Pattern](https://en.wikipedia.org/wiki/Visitor_pattern).

### Acyclic Visitor ###

The [Visitor Pattern](https://en.wikipedia.org/wiki/Visitor_pattern) allows a new abstract behavior addition without changing the host 
classes throughout the hierarchy. **Visitor** is described by the GoF's book as:

>Represent an operation to be performed on elements of an object structure. 
>Visitor lets you define a new operation without changing the classes of the 
>elements on which it operates. ― Gamma, Erich

It means that you can achieve polymorphism by adding behavior, instead of spreading 
common operations all over hierarchy. It means too that, this task is doable through 
composition, rather than inheritance.
Therefore, [Visitor Pattern](https://en.wikipedia.org/wiki/Visitor_pattern) is also a great ally to follow the [Single Responsibility Principle](https://en.wikipedia.org/wiki/Single_responsibility_principle) 
as well as the [Open/Closed Principle](https://en.wikipedia.org/wiki/Open/closed_principle). However, one of the Visitor worst drawbacks is 
that It is not possible to add new leaf classes to the hierarchy without creating 
cyclic dependency among the visitor classes.

Here is where [Acyclic Visitor](http://wiki.c2.com/?AcyclicVisitor), fortunately, comes out:

>The Acyclic Visitor pattern allows new functions to be added to existing 
>class hierarchies without affecting those hierarchies, and without creating 
>the dependency cycles that are inherent to the GoF Visitor pattern. ― Martin, Robert

[Acyclic Visitor](http://wiki.c2.com/?AcyclicVisitor) is a variation of the Visitor Pattern that allows us to change 
the Visitor hierarchy through hierarchy casting and inheritance, thereby avoiding the 
cyclic dependency among visitor classes.

### Clarifying it, in practical terms ###

[Acyclic Visitor](http://wiki.c2.com/?AcyclicVisitor) is going to being applied to the calculation of the measures of geometric forms. 
It is going to being used as an alternative to the inheritance of a common operation.
Thus, instead of adding a common method as follows:

- calculateArea()
- calculateRadius()
- calculateDiameter()

Classes like `Geometry::Measure::Area`, `Geometry::Measure::Radius` and `Geometry::Measure::Diameter` 
are going to being defined to deal with the responsibility of the measures calculation, 
hence avoiding potential violations to the [Single Responsibility Principle](https://en.wikipedia.org/wiki/Single_responsibility_principle) that states:

`A class should have only one reason to change.`

**Shape** is the top of the hierarchy of the geometric forms as follows:
```cpp

    class Shape
    {
    public:
        virtual ~Shape()
        { };

        virtual void draw() = 0;

    };

```

Below the **Shape** interface, there are classes for all another specific sort of geometric forms:

+ Curved
+ Quadrilateral
+ Triangle

```cpp

    class Quadrilateral : public Shape
    {
    public:
        virtual ~Quadrilateral()
        { };

        virtual Angle getAngleAB() const = 0;
        virtual Angle getAngleBC() const = 0;
        virtual Angle getAngleCD() const = 0;
        virtual Angle getAngleDA() const = 0;

        virtual Segment getSideA() const = 0;
        virtual Segment getSideB() const = 0;
        virtual Segment getSideC() const = 0;
        virtual Segment getSideD() const = 0;

    };

```

```cpp

    class Triangle
    {
    public:
        virtual ~Triangle()
        { };

        virtual Angle getAngleAB() const = 0;
        virtual Angle getAngleBC() const = 0;
        virtual Angle getAngleCA() const = 0;

        virtual Segment getSideA() const = 0;
        virtual Segment getSideB() const = 0;
        virtual Segment getSideC() const = 0;

    };

```

```cpp

    class Curved : public Shape
    {
    public:
        virtual ~Curved()
        { };

    };

```


### Usage of the Acyclic Visitor ###

Concrete shape classes are defined as `Measurable` classes.
It means just that these classes accept a visitor `Measure` class as a guest.
So that, `Geometry::Measure::Area` is accountable to the calculation of the area, 
as well as `Geometry::Measure::Circumference` is responsible for the calculation 
of the circumference, so forth.

### Defining the visitable shapes ###

A **measurable** quadrangle:
```cpp

        class Rectangle
            : public Quadrilateral,
              public Util::Measurable 
        {
        public:
            MEASURABLE()

            ~Rectangle();
            Rectangle(
                const Angle, const Angle, const Angle, const Angle,
                const Segment, const Segment, const Segment, const Segment
            );

            void draw();

            Angle getAngleAB() const;
            Angle getAngleBC() const;
            Angle getAngleCD() const;
            Angle getAngleDA() const;

            Segment getSideA() const;
            Segment getSideB() const;
            Segment getSideC() const;
            Segment getSideD() const;

            ... 

        };

```

A **measurable** curved:
```cpp

    class Circle :
        public Shape,
        public Util::Measurable
    {
    public:
        MEASURABLE()

        ~Circle();
        Circle(const float);

        void draw();
        float getDiameter() const;

        ...

    };

```

A **measurable** triangle:
```cpp

    class Isosceles :
        public Triangle,
        public Util::Measurable
    {
    public:
        MEASURABLE()

        ~Isosceles();
        Isosceles(
            const Angle, const Angle, const Angle,
            const Segment, const Segment, const Segment
        );

        void draw();

        Angle getAngleAB() const;
        Angle getAngleBC() const;
        Angle getAngleCA() const;

        Segment getSideA() const;
        Segment getSideB() const;
        Segment getSideC() const;

        ...

    };


```

### The visitor measure classes ###

For measure the **Area** of any shape:
```cpp

    class Area :
        public Util::Visitor,
        public Util::Measure<Circle>,
        public Util::Measure<Ellipse>,
        public Util::Measure<Polygon::Square>,
        public Util::Measure<Polygon::Rectangle>,
        public Util::Measure<Polygon::Scalene>,
        public Util::Measure<Polygon::Isosceles>,
        public Util::Measure<Polygon::Equilateral>
    {
    public:
        ... 
        
        void visit(Circle &);
        void visit(Ellipse &);
        void visit(Polygon::Square &);
        void visit(Polygon::Rectangle &);
        void visit(Polygon::Scalene &);
        void visit(Polygon::Isosceles &);
        void visit(Polygon::Equilateral &);
        
        ... 

    };

```

For measure the **Radius** of any shape:
```cpp

    class Radius :
        public Util::Visitor,
        public Util::Measure<Circle>,
        public Util::Measure<Ellipse>
    {
    public:
        ...

        void visit(Circle &);
        void visit(Ellipse &);

        ...
    };

```

### Finally, everything working together ###

As a result, **Shape** classes have any need to know about their **Measure** classes. 
Defining a **Shape** class as **Measurable** is everything that it is needed to this 
class accepts a **Measure** class whatever it is.

```cpp

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

```

The result is:
```
    Acyclic Visitor Shape's Measurements

    Circle:
    Area:          1963.45
    Radius:        25
    Circumference: 157.076

    Ellipse:
    Area:          314.152
    Radius:        10
    Circumference: 62.8304

    Scalene Triangle:
    Area:      22.1853
    Perimeter: 25

    Isosceles Triangle:
    Area:      49.6078
    Perimeter: 35

    Equilateral Triangle:
    Area:      27.7128
    Perimeter: 24

    Square:
    Area:      100
    Perimeter: 40

    Rectangle:
    Area:      200
    Perimeter: 60

    Process finished with exit code 0

```

### Useful links ###
* [Google Test](https://github.com/google/googletest/blob/master/googletest/docs/Primer.md)

### References ###

* **Alexandrescu, Andrei**, [Modern C++ Design: Generic Programming and Design Patterns Applied](https://www.amazon.de/Modern-Generic-Programming-Patterns-Applied/dp/0201704315)
* **GAMMA, Erich** et al, [Design Patterns: Elements of Reusable Object-Oriented Software](https://www.amazon.com/Design-Patterns-Elements-Reusable-Object-Oriented/dp/0201633612)
* **Martin, Robert**, [Agile Principles, Patterns, and Practices in C#](https://www.amazon.com/Agile-Principles-Patterns-Practices-C/dp/0131857258)
