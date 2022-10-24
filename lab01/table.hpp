#pragma once
#include <string>

class Table {

    private:

        const std::string default_name = "Tablica";
        const int default_array_len = 5;

        std::string name;
        int array_len;
        int *array;

    public:

        Table();
        Table(std::string name, int array_len);
        Table(const Table &otherTable);
        ~Table();
        Table *clone();
        void setName(std::string name);
        bool setArrayLen(int array_len);
        void printTable();
};

void modTable(Table table, int array_len);
void modTable(Table *table, int array_len);