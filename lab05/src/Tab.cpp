#include <iostream>

#include "Tab.hpp"


const int Tab::default_size = 10;

Tab::Tab() {

    size = default_size;
    table = new int[size];

    std::cout << "Constructor" << std::endl;
}

Tab::Tab(const Tab& other) {

    copy(other);
    std::cout << "Copy constructor" << std::endl;
}

Tab::Tab(Tab&& other) {

    size = other.size;
    table = other.table;
    other.table = nullptr;

    std::cout << "Move constructor" << std::endl;
}

Tab::~Tab() {

    if (table != nullptr)
        delete[] table;

    std::cout << "Destructor" << std::endl;
}

void Tab::copy(const Tab& other) {

    size = other.size;
    table = new int[size];

    for (int i = 0; i < size; i++)
        table[i] = other.table[i];
}

Tab Tab::operator=(const Tab& other) {

    if (table != nullptr)
        delete[] table;

    copy(other);

    std::cout << "Copy assigment" << std::endl;
    return *this;
}

Tab Tab::operator=(Tab&& other) {

    if (table != nullptr)
        delete[] table;

    size = other.size;
    table = other.table;
    other.table = nullptr;

    std::cout << "Move assigment" << std::endl;
    return std::move(*this);
}

bool Tab::setSize(int size) {

    if (size <= 0)
        return false;
    if (size == this->size)
        return true;
    
    int *temp = new int[size];

    for (int i = 0; i < size; i++) {

        if (i < this->size)
            temp[i] = table[i];
        else
            temp[i] = 0;
    }
    
    delete[] table;
    this->size = size;
    table = temp;

    return true;
}

int Tab::getSize() {

    return size;
}