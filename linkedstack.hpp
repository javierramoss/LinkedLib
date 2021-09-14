#ifndef LINKEDSTACK_HPP
#define LINKEDSTACK_HPP

#include "linkedlist.hpp"

template<typename T>
class LinkedStack : public LinkedList<T> {

private:

public:
    T top() const {
        return this->head();
    }

    T back() const {
        return this->tail();
    }

};

#endif