#include <iostream>

#include "Tab.hpp"
#include "Table.hpp"


void blank() {

    std::cout << std::endl;
}

Tab createTabCopy() {

    Tab tab;
    tab.setSize(5);
    return tab;
}

Tab createTabMove() {

    Tab tab;
    tab.setSize(5);
    return std::move(tab);
}

Table createTableCopy() {

    Table table(5);
    return table;
}

Table createTableMove() {

    Table table(5);
    return std::move(table);
}

void testTabCopy() {
    
    Tab tab1 = createTabCopy();
    blank();
    Tab tab2 = tab1;
    blank();
    Tab tab3;
    tab3 = tab2;
    blank();
}

void testTabMove() {

    Tab tab1 = createTabMove();
    blank();
    Tab tab2 = std::move(tab1);
    blank();
    Tab tab3;
    tab3 = std::move(tab2);
    blank();
}

void testTableCopy() {

    Table table1 = createTableCopy();
    blank();
    Table table2 = table1;
    blank();
    Table table3;
    table3 = table2;
    blank();
    Table table4 = table3 + table2;
    blank();
}

void testTableMove() {

    Table table1 = createTableMove();
    blank();
    Table table2 = std::move(table1);
    blank();
    Table table3;
    table3 = std::move(table2);
    blank();
    Table table4 = std::move(table3 + std::move(Table()));
    blank();
}

int main() {

    //testTabCopy();
    //testTabMove();
    testTableCopy();
    //testTableMove();
}
