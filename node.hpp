#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template<typename T>
struct Node {
    T value;
    Node* next;
    Node* prev;
};

#endif