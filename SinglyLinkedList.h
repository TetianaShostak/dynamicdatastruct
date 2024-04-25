//
// Created by tanya on 25.04.2024.
//
#ifndef UNTITLED5_SINGLYLINKEDLIST_H
#define UNTITLED5_SINGLYLINKEDLIST_H

#pragma once
#include <iostream>
#include "Node.h"

template<typename T>
class SinglyLinkedList {
private:
    shared_ptr<Node<T>> head;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void push_front(T value);
    void push_back(T value);
    T pop_front();
    T& operator[](size_t index);
    size_t size() const;
    bool empty() const;
    bool contains(T value) const;
    void print() const;
};

#endif //UNTITLED5_SINGLYLINKEDLIST_H
