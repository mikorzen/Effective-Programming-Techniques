#include <iostream>

#include "Table.hpp"


const int Table::default_size = 10;

Table::Table() {

    size = default_size;
    table = new int[size];
}

Table::Table(const Table& other) {

    copy(other);
    std::cout << "Copying";
}

Table::~Table() {

    if (table != NULL)
        delete table;

    std::cout << "Destroying";
}

void Table::copy(const Table& other) {

    size = other.size;
    table = new int[size];

    for (int i = 0; i < size; i++)
        table[i] = other.table[i];
}

Table& Table::operator=(const Table& other) {

    if (table != NULL)
        delete table;

    copy(other);
    std::cout << "Using \"=\" operator";
    return *this;
}

bool Table::setSize(int size) {

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

int Table::getSize() {

    return size;
}