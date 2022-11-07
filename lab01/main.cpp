#include "table_mod.hpp"
#include <iostream>


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