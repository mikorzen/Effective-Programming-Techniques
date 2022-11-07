#include "table.hpp"
#include <iostream>
#include <string>


const std::string Table::default_name = "Tablica";
const int Table::default_array_len = 5;
const bool Table::default_shared = false;

Table::Table() {

    name = default_name;
    array_len = default_array_len;
    array = new int[array_len];
    shared = default_shared;

    std::cout << "bezp: '" << name << "'" << std::endl;
}

Table::Table(std::string name, int array_len) {

    this->name = name;
    if (array_len <= 0)
        array_len = default_array_len;
    this->array_len = array_len;
    array = new int[array_len];
    shared = default_shared;

    std::cout << "param: '" << name << "'" << std::endl;
}

Table::Table(const Table &otherTable) {

    name = otherTable.name + "_copy";
    array_len = otherTable.array_len;
    array = new int[array_len];
    shared = default_shared;

    for (int i = 0; i < array_len; i++)
        array[i] = otherTable.array[i];

    std::cout << "kopiuj: '" << name << "'" << std::endl;
}

/* Table::~Table() {

    if (!shared)
        delete[] array;
    std::cout << "usuwam: '" << name << "'" << std::endl;
} */

void Table::operator=(const Table &otherTable) {

    array = otherTable.array;
    array_len = otherTable.array_len;
}

Table Table::operator+(Table &otherTable) {

    Table table;

    int array_len = this->array_len + otherTable.array_len;
    int *array = new int[array_len];

    for (int i = 0; i < this->array_len; i++)
        array[i] = this->array[i];
    for (int i = this->array_len; i < array_len; i++)
        array[i] = otherTable.array[i - this->array_len];

    table.array_len = array_len;
    delete[] table.array;
    table.array = array;
    return table;
}

Table *Table::clone() {
    
    return new Table(*this);
}

Table *Table::share() {

    Table *table = new Table(name + "_shared", array_len);
    delete[] table->array;
    table->array = array;
    table->shared = true;

    return table;
}

void Table::setName(std::string name) {

    this->name = name;
}

bool Table::setArrayLen(int array_len) {

    if (array_len <= 0)
        return false;
    if (array_len == this->array_len)
        return true;
    
    int *temp = new int[array_len];

    for (int i = 0; i < array_len; i++) {
        if (i < this->array_len)
            temp[i] = array[i];
        else
            temp[i] = 0;
    }
    
    delete[] array;
    this->array_len = array_len;
    array = temp;

    return true;
}

void Table::setValueAt(int index, int value) {

    if (index < 0 || index >= array_len)
        return;

    array[index] = value;
}

void Table::printTable() {

    for (int i = 0; i < array_len; i++)
        std::cout << name << "[" << i << "] = " << array[i] << std::endl;
}

void Table::fillTable(int filler) {

    for (int i = 0; i < array_len; i++)
        array[i] = filler;
}

void Table::fillTableInc(int filler) {

    for (int i = 0; i < array_len; i++)
        array[i] = filler + i;
}


void modTable(Table table, int array_len) {

    table.setArrayLen(array_len);
}

void modTable(Table *table, int array_len) {

    table->setArrayLen(array_len);
}