#include <iostream>
#include <string>

#include "Table.hpp"


const std::string Table::default_name = "Table";
const int Table::default_size = 5;

Table::Table() {

    name = default_name;
    size = default_size;
    table = new int[size];

    std::cout << "Constructor: '" << name << "'" << std::endl;
}

Table::Table(int size) {

    name = default_name;
    if (size <= 0)
        size = size;
    this->size = size;
    table = new int[size];

    std::cout << "Param. constructor: '" << name << "'" << std::endl;
}

Table::Table(std::string name, int size) {

    this->name = name;
    if (size <= 0)
        size = size;
    this->size = size;
    table = new int[size];

    std::cout << "Param. constructor: '" << name << "'" << std::endl;
}

Table::Table(const Table& other) {

    name = other.name + "_copc";
    size = other.size;
    table = new int[size];

    for (int i = 0; i < size; i++)
        table[i] = other.table[i];

    std::cout << "Copy constructor: '" << name << "'" << std::endl;
}

Table::Table(Table&& other) {

    name = other.name + "_movc";
    size = other.size;
    table = other.table;
    other.table = nullptr;

    std::cout << "Move constructor: '" << name << "'" << std::endl;
}

Table::~Table() {

    if (table != nullptr)
        delete[] table;
    
    std::cout << "Destructor: '" << name << "'" << std::endl;
}

Table& Table::operator=(const Table& other) {

    if (table != nullptr)
        delete[] table;

    name = other.name + "_copa";
    size = other.size;
    table = new int[size];
    for (int i = 0; i < size; i++)
        table[i] = other.table[i];

    std::cout << "Copy assignment: '" << name << "'" << std::endl;
    return *this;
}

Table& Table::operator=(Table&& other) {

    if (table != nullptr)
        delete[] table;

    name = other.name + "_mova";
    size = other.size;
    table = other.table;
    other.table = nullptr;

    std::cout << "Move assignment: '" << name << "'" << std::endl;
    return *this;
}

Table Table::operator+(const Table& other) {

    int newSize = size + other.size;
    Table newTable("Table_add", size);

    for (int i = 0; i < size; i++)
        newTable.table[i] = table[i];
    for (int i = size; i < newSize; i++)
        newTable.table[i] = other.table[i - size];

    std::cout << "Addition" << std::endl;
    return newTable;
}

Table Table::operator+(Table&& other) {
    
    int newSize = size + other.size;
    Table newTable("Table_addm", newSize);

    for (int i = 0; i < size; i++)
        newTable.table[i] = table[i];
    for (int i = size; i < newSize; i++)
        newTable.table[i] = other.table[i - size];

    std::cout << "Move addition" << std::endl;
    return std::move(newTable);
}

Table* Table::clone() {
    
    return new Table(*this);
}

bool Table::setName(std::string name) {

    this->name = name;
    return true;
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

bool Table::setValueAt(int index, int value) {

    if (index < 0 || index >= size)
        return false;

    table[index] = value;
    return true;
}

std::string Table::getName() {

    return name;
}

int Table::getSize() {

    return size;
}

int Table::getValueAt(int index) {

    if (index < 0 || index >= size)
        return 0;

    return table[index];
}