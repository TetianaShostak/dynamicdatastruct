//
// Created by tanya on 25.04.2024.
//

#ifndef UNTITLED5_NODE_H
#define UNTITLED5_NODE_H
#pragma once
#include <memory>
using namespace std;

template<typename T>
struct Node {
    T data;
    shared_ptr<Node<T>> next;
    shared_ptr<Node<T>> prev;

    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

#endif //UNTITLED5_NODE_H
