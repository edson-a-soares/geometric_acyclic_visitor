#ifndef ACYCLIC_VISITOR_GEOMETRY_SEGMENT_H
#define ACYCLIC_VISITOR_GEOMETRY_SEGMENT_H

namespace Geometry
{

    class Segment
    {
    public:
        Segment(const float);

        float getLength() const;

    private:
        const float length;

    };

}

#endif
