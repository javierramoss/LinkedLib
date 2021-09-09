#ifndef LINKEDQUEUE_HPP
#define LINKEDQUEUE_HPP

#include "linkedlist.hpp"

template<typename T>
class LinkedQueue : public LinkedList<T> {

private:

public:
    T top() const {
        return LinkedList<T>::head();
    }

    T back() const {
        return LinkedList<T>::tail();
    }

};

#endif