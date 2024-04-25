//
// Created by tanya on 25.04.2024.
//

#include "DoublyLinkedList.h"
using namespace std;

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
void DoublyLinkedList<T>::push_front(T value) {
    auto new_node = make_shared<Node<T>>(value);
    new_node->next = head;
    if (head) head->prev = new_node;
    else tail = new_node;
    head = new_node;
}

template<typename T>
void DoublyLinkedList<T>::push_back(T value) {
    auto new_node = make_shared<Node<T>>(value);
    if (tail) {
        tail->next = new_node;
        new_node->prev = tail;
    } else {
        head = new_node;
    }
    tail = new_node;
}




template<typename T>
T DoublyLinkedList<T>::pop_front() {
    if (!head) throw runtime_error("List is empty");
    auto val = head->data;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    return val;
}

template<typename T>
T DoublyLinkedList<T>::pop_back() {
    if (!tail) throw runtime_error("List is empty");
    auto val = tail->data;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    return val;
}




template<typename T>
T& DoublyLinkedList<T>::operator[](size_t index) {
    auto current = (index < size() / 2) ? head : tail;



    size_t idx = (index < size() / 2) ? 0 : size() - 1;


    while (current && idx != index) {
        current = (index < size() / 2) ?
                current->next : current->prev;


        idx += (index < size() / 2) ? 1 : -1;
    }


    if (!current) throw out_of_range("Index out of range");
    return current->data;
}

template<typename T>
size_t DoublyLinkedList<T>::size() const {
    size_t count = 0;
    auto current = head;
    while (current) {
        ++count;
        current = current->next;
    }
    return count;
}

template<typename T>
bool DoublyLinkedList<T>::empty() const {
    return head == nullptr;
}

template<typename T>
bool DoublyLinkedList<T>::contains(T value) const {
    auto current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const {
    auto current= head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<string>;