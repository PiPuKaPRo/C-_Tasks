#include "DoublyLinkedList.h"

template<typename T>
DoublyLinkedList<T>::Node::Node(const T &value) : data(value), prev(nullptr), next(nullptr) {}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node *current = head;
    while (current) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
void DoublyLinkedList<T>::append(const T &value) {
    Node *newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
    }
    tail = newNode;
    ++size;
}

template<typename T>
void DoublyLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node *current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    if (current->prev) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }
    if (current->next) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }
    delete current;
    --size;
}

template<typename T>
int DoublyLinkedList<T>::getSize() const {
    return size;
}

template<typename T>
T &DoublyLinkedList<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node *current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}
