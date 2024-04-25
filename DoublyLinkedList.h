//
// Created by tanya on 25.04.2024.
//

#ifndef UNTITLED5_DOUBLYLINKEDLIST_H
#define UNTITLED5_DOUBLYLINKEDLIST_H

#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
template<typename T>
class DoublyLinkedList {
private:
    shared_ptr<Node<T>> head, tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void push_front(T value);
    void push_back(T value);
    T pop_front();
    T pop_back();
    T& operator[](size_t index);
    size_t size() const;
    bool empty() const;
    bool contains(T value) const;
    void print() const;
};

#endif //UNTITLED5_DOUBLYLINKEDLIST_H
