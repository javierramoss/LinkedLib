#ifndef NODE
#define NODE

#include <iostream>

template<typename T>
struct Node {
    T value;
    Node* next;
    Node* prev;
};

#endif