
#include <iostream>
#include "SinglyLinkedList.cpp"
#include "DoublyLinkedList.cpp"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"


int main() {



    SinglyLinkedList<int> sList;
    sList.push_front(10);

    sList.push_front(20);
    sList.print();

    DoublyLinkedList<int> dList;
    dList.push_back(30);
    dList.push_back(40);

    dList.print();

    return 0;
}
