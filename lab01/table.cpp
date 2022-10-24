#include "table.hpp"
#include <iostream>
#include <string>


Table::Table() {

    name = default_name;
    array_len = default_array_len;
    array = new int[array_len];

    std::cout << "bezp: '" << name << "'" << std::endl;
}

Table::Table(std::string name, int array_len) {

    this->name = name;
    this->array_len = array_len;
    array = new int[array_len];
}

Table::Table(const Table &otherTable) {

    name = otherTable.name + "_copy";
    array_len = otherTable.array_len;
    array = new int[array_len];

    for (int i = 0; i < array_len; i++)
        array[i] = otherTable.array[i];

    std::cout << "kopiuj: '" << name << "'" << std::endl;
}

Table::~Table() {

    delete[] array;
    std::cout << "usuwam: '" << name << "'" << std::endl;
} 

Table *Table::clone() {
    
    return new Table(*this);
}

void Table::setName(std::string name) {

    this->name = name;
}

bool Table::setArrayLen(int array_len) {

    if (array_len <= this->array_len)
        return false;

    this->array_len = array_len;
    int *temp = new int[array_len];

    for (int i = 0; i < array_len; i++)
        temp[i] = array[i];
    
    delete[] array;
    array = temp;

    return true;
}

void Table::printTable() {

    for (int i = 0; i < array_len; i++)
        std::cout << name << "[" << i << "] = " << array[i] << std::endl;
}


void modTable(Table table, int array_len) {

    table.setArrayLen(array_len);
}

void modTable(Table *table, int array_len) {

    table->setArrayLen(array_len);
}


int main() {

    Table tablica = Table();
    Table *tablicaClone = tablica.clone();
    tablica.printTable();
    std::cout << std::endl;
    tablicaClone->printTable();
    std::cout << std::endl;

    modTable(tablica, 3);
    tablica.printTable();
    std::cout << std::endl;

    modTable(tablicaClone, 3);
    tablicaClone->printTable();
    std::cout << std::endl;
    return 0;
}