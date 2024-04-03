#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    // Пример использования списка для хранения int
    DoublyLinkedList<int> intList;
    intList.append(10);
    intList.append(20);
    intList.append(30);

    std::cout << "Integer List Size: " << intList.getSize() << std::endl;
    std::cout << "Element at index 1: " << intList[1] << std::endl;

    // Пример использования списка для хранения строк
    DoublyLinkedList<std::string> stringList;
    stringList.append("Hello");
    stringList.append("world");
    stringList.append("!");

    std::cout << "String List Size: " << stringList.getSize() << std::endl;
    std::cout << "Element at index 2: " << stringList[2] << std::endl;

    return 0;
}
