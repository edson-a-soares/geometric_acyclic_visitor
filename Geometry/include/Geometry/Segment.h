#ifndef ACYCLIC_VISITOR_GEOMETRY_SEGMENT_H
#define ACYCLIC_VISITOR_GEOMETRY_SEGMENT_H

namespace Geometry
{

    class Segment
    {
    public:
        Segment(int);

        void setLength(int);
        int getLength() const;

    private:
        int length;

    };

}

#endif
