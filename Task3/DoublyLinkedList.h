#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdexcept>
#include <string>

template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node *prev;
        Node *next;

        Node(const T &value);
    };

    Node *head;
    Node *tail;
    int size;

public:
    DoublyLinkedList();

    ~DoublyLinkedList();

    void append(const T &value);

    void removeAt(int index);

    int getSize() const;

    T &operator[](int index);
};

#endif
