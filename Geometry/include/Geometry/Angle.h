#ifndef ACYCLIC_VISITOR_GEOMETRY_ANGLE_H
#define ACYCLIC_VISITOR_GEOMETRY_ANGLE_H

namespace Geometry
{

    class Angle
    {
    public:
        Angle(int);

        void setLength(int);
        int getLength() const;

    private:
        int length;

    };

}

#endif
