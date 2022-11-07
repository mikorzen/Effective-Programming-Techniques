#pragma once
#include <string>

class Table {

    private:

        std::string name;
        int array_len;
        int *array;
        bool shared;

    public:

        static const std::string default_name;
        static const int default_array_len;
        static const bool default_shared;

        Table();
        Table(std::string name, int array_len);
        Table(const Table &otherTable);
        //~Table();

        Table *clone();
        Table *share();

        void operator=(const Table &otherTable);
        Table operator+(Table &otherTable);

        void setName(std::string name);
        bool setArrayLen(int array_len);
        void setValueAt(int index, int value);

        void printTable();
        void fillTable(int filler);
        void fillTableInc(int filler);
};

void modTable(Table table, int array_len);
void modTable(Table *table, int array_len);