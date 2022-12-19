#pragma once

#include <string>


class Table {

    private:

        std::string name;
        int size;
        int* table;

    public:

        static const int default_size;
        static const std::string default_name;

        Table();
        Table(int size);
        Table(std::string name, int size);
        Table(const Table& other);
        Table(Table&& other);
        ~Table();

        Table* clone();

        Table& operator=(const Table& other);
        Table& operator=(Table&& other);

        Table operator+(const Table& other);
        Table operator+(Table&& other);

        bool setName(std::string name);
        bool setSize(int size);
        bool setValueAt(int index, int value);

        std::string getName();
        int getSize();
        int getValueAt(int index);
};

void modTable(Table table, int array_len);
void modTable(Table *table, int array_len);