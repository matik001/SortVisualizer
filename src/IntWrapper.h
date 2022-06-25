#ifndef SORTVISUALIZER_INTWRAPPER_H
#define SORTVISUALIZER_INTWRAPPER_H


#include "Diagram.h"

class IntWrapper {
    int pos;
    Diagram *_diagram;
public:

    static IntWrapper create(Diagram &diagram, int pos);

    void exit_if_closed() const;

    int comp(const IntWrapper &b) const;

    bool operator<(const IntWrapper &b) const;

    bool operator<=(const IntWrapper &b) const;

    bool operator==(const IntWrapper &b) const;

    bool operator!=(const IntWrapper &b) const;

    bool operator>(const IntWrapper &b) const;

    bool operator>=(const IntWrapper &b) const;

    void operator=(const int val);

    void copy(const IntWrapper &from);

    int get_value() const;

    friend void swap(IntWrapper &a, IntWrapper &b) {
        a._diagram->swap(a.pos, b.pos);
    }
};


#endif //SORTVISUALIZER_INTWRAPPER_H
