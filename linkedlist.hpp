#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "node.hpp"

template<typename T>
class LinkedList {
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<T>& linkedlist) {
        for (Node<T>* temp = linkedlist._head; temp != nullptr; temp = temp->next)
            out << temp->value << "\n";
        return out;
    }

protected:
    Node<T>* _head;
    Node<T>* _tail;
    T undefined;
    int _size;

public:
    //default constructor
    LinkedList() : _head(nullptr), _tail(nullptr), undefined(T()), _size(0) {};
    LinkedList(T undefined) : _head(nullptr), _tail(nullptr), undefined(undefined), _size(0) {};

    //copy constructor
    LinkedList(const LinkedList& linkedlist) {
        copy(linkedlist);
    }
    
    //copy assignment operator
    LinkedList& operator=(const LinkedList& linkedlist) {
        if (this != &linkedlist) {
            this->~LinkedList();
            this->copy(linkedlist);
        }
        return *this;
    }

    ~LinkedList() {
        while (!empty()) {
            pop();
        }
    }

    void copy(const LinkedList& linkedlist) {
        _head = linkedlist._head;
        _tail = linkedlist._tail;
        undefined = linkedlist.undefined;
        _size = 0;

        Node<T>* temp = linkedlist._head;
        while (temp != nullptr) {
            push(temp->value);
            temp = temp->next;
        }
    }

    int empty() const {
        if (_size == 0)
            return 1;
        return 0;
    }

    int size() const {
        return _size;
    }

    T head() const {
        if (_size > 0)
            return _head->value;
        return undefined;
    }

    T tail() const {
        if (_size > 0)
            return _tail->value;
        return undefined;
    }

    T pop() {
        T value = undefined;
        if (_size == 1) {
            value = _tail->value;
            delete _tail;
            _head = _tail = nullptr;
            _size--;
        }
        else if (_size > 1) {
            value = _tail->value;
            Node<T>* newTail = _tail->prev;
            delete _tail;
            _tail = newTail;
            _tail->next = nullptr;
            _size--;
        }
        return value;
    }

    void push(T x) {
        Node<T>* newNode = new Node<T>;
        newNode->value = x;

        if (_size == 0) {
            newNode->prev = newNode->next = nullptr;
            _head = _tail = newNode;
        }
        else if (_size > 0) {
            _tail->next = newNode;
            newNode->prev = _tail;
            newNode->next = nullptr;
            _tail = newNode;
        }
        _size++;
    }

};

#endif