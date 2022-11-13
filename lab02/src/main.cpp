#include "table.hpp"
#include <iostream>

int main() {

    Table table1("Tab1", 5), table2("Tab2", 5);
    table1.setArrayLen(6);
    table2.setArrayLen(4);

    table1.fillTableInc(1);
    table2.fillTableInc(51);

    // błąd przy obecnym destruktorze - próba wielokrotnej dealokacji tej samej tablicy
    table1 = table2;

    table2.setValueAt(2, 123);

    table1.printTable();
    std::cout << std::endl;
    table2.printTable();
    std::cout << std::endl;

    std::cout << "konkatenacja" << std::endl;
    Table table3 = table1 + table2;
    table3.printTable();

    return 0;
}