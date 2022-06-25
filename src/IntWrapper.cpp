#include <cstdlib>
#include "IntWrapper.h"
#include "Diagram.h"


IntWrapper IntWrapper::create(Diagram &diagram, int pos) {
    IntWrapper res;
    res._diagram = &diagram;
    res.pos = pos;
    return res;
}

void IntWrapper::exit_if_closed() const {
    if (!_diagram->is_alive) {
        exit(0);
    }
}

int IntWrapper::comp(const IntWrapper &b) const {
    exit_if_closed();
    return _diagram->compare_elements(pos, b.pos);
}

bool IntWrapper::operator<(const IntWrapper &b) const {
    exit_if_closed();
    return _diagram->compare_elements(pos, b.pos) == -1;
}

bool IntWrapper::operator<=(const IntWrapper &b) const {
    exit_if_closed();
    return _diagram->compare_elements(pos, b.pos) != 1;
}

bool IntWrapper::operator==(const IntWrapper &b) const {
    exit_if_closed();
    return _diagram->compare_elements(pos, b.pos) == 0;
}

bool IntWrapper::operator!=(const IntWrapper &b) const {
    exit_if_closed();
    return _diagram->compare_elements(pos, b.pos) != 0;
}

bool IntWrapper::operator>(const IntWrapper &b) const {
    exit_if_closed();
    return _diagram->compare_elements(pos, b.pos) == 1;
}

bool IntWrapper::operator>=(const IntWrapper &b) const {
    exit_if_closed();
    return _diagram->compare_elements(pos, b.pos) != -1;
}


void IntWrapper::operator=(const int val) {
    _diagram->set_element(pos, val);
}

void IntWrapper::copy(const IntWrapper &from) {
    pos = from.pos;
    _diagram = from._diagram;
}

int IntWrapper::get_value() const {
    exit_if_closed();
    return _diagram->get_value(pos);
}

