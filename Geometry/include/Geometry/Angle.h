#ifndef ACYCLIC_VISITOR_GEOMETRY_ANGLE_H
#define ACYCLIC_VISITOR_GEOMETRY_ANGLE_H

namespace Geometry
{

    class Angle
    {
    public:
        Angle(const float);

        float getLength() const;

    private:
        const float length;

    };

}

#endif
