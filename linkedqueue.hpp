#ifndef LINKEDQUEUE_HPP
#define LINKEDQUEUE_HPP

#include "linkedlist.hpp"

template<typename T>
class LinkedQueue : public LinkedList<T> {

private:

public:
    T top() const {
        return this->head();
    }

    T back() const {
        return this->tail();
    }

    T pop() {
        T value = this->undefined;
        if (this->_size == 1) {
            value = this->_head->value;
            delete this->_head;
            this->_head = this->_tail = nullptr;
            this->_size--;
        }
        else if (this->_size > 1) {
            value = this->_head->value;
            Node<T>* newHead = this->_head->next;
            delete this->_head;
            this->_head = newHead;
            this->_head->prev = nullptr;
            this->_size--;
        }
        return value;
    }

};

#endif