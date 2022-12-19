#pragma once


class Table {

    private:

        int *table;
        int size;

        void copy(const Table& other);

    public:

        static const int default_size;

        Table();
        Table(const Table& other);
        ~Table();

        Table& operator=(const Table& other);

        bool setSize(int size);
        int getSize();
};