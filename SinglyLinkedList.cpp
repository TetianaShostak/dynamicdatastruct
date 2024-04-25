//
// Created by tanya on 25.04.2024.
//

#include "SinglyLinkedList.h"
using namespace std;

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr) {}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    while (!empty()) {
        pop_front();
    }
}





template<typename T>
void SinglyLinkedList<T>::push_front(T value) {
    auto new_node = make_shared<Node<T>>(value);
    new_node->next = head;
    head = new_node;
}

template<typename T>
void SinglyLinkedList<T>::push_back(T value) {
    auto new_node = make_shared<Node<T>>(value);
    if (!head) {
        head = new_node;
        return;
    }
    auto current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
}



template<typename T>
T SinglyLinkedList<T>::pop_front() {
    if (!head) throw runtime_error ("is empty");
    auto val = head->data;
    head = head->next;
    return val;
}






template<typename T>
T& SinglyLinkedList<T>::operator[](size_t index) {
    auto current = head;
    size_t idx = 0;
    while (current && idx < index) {
        current = current->next;
        ++idx;
    }
    if (!current) throw out_of_range ("Index out of range");
    return current->data;
}








template<typename T>
size_t SinglyLinkedList<T>::size() const {
    size_t count = 0;
    auto current = head;
    while (current) {
        ++count;
        current = current->next;
    }
    return count;
}

template<typename T>
bool SinglyLinkedList<T>::empty() const {
    return head == nullptr;
}

template<typename T>
bool SinglyLinkedList<T>::contains(T value) const {
    auto current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

template<typename T>
void SinglyLinkedList<T>::print() const {
    auto current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template class SinglyLinkedList<int>;
template class SinglyLinkedList<string>;