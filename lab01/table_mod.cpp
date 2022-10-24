#include "table_mod.hpp"
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

    if (!shared)
        delete[] array;
    std::cout << "usuwam: '" << name << "'" << std::endl;
} 

Table *Table::clone() {
    
    return new Table(*this);
}

Table *Table::share() {

    Table *table = new Table(name + "_shared", array_len);
    table->array = array;
    table->shared = true;

    return table;
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

void Table::fillTable(int filler) {

    for (int i = 0; i < array_len; i++)
        array[i] = filler;
}


void modTable(Table table, int array_len) {

    table.setArrayLen(array_len);
}

void modTable(Table *table, int array_len) {

    table->setArrayLen(array_len);
}


int main() {

    Table table = Table();
    Table *tableShared = table.share();
    Table *tableShared2 = table.share();

    table.printTable();
    tableShared->fillTable(5);
    std::cout << std::endl;
    table.printTable();

    delete tableShared;
    delete tableShared2;

    return 0;
}