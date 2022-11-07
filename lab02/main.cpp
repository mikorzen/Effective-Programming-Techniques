#include "table.hpp"
#include <iostream>

int main() {

    Table table1, table2;
    table1.setArrayLen(6);
    table2.setArrayLen(4);

    table1.fillTableInc(1);
    table2.fillTableInc(51);

    table1 = table2;

    table2.setValueAt(2, 123);

    table1.printTable();
    std::cout << std::endl;
    table2.printTable();

    Table table3 = table1 + table2;
    std::cout << std::endl;
    table3.printTable();

    return 0;
}