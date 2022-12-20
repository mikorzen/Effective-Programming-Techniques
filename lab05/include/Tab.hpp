#pragma once


class Tab {

    private:

        int size;
        int* table;

        void copy(const Tab& other);

    public:

        static const int default_size;

        Tab();
        Tab(const Tab& other);
        Tab(Tab&& other);
        ~Tab();

        Tab& operator=(const Tab& other);
        Tab& operator=(Tab&& other);

        bool setSize(int size);
        int getSize();
};
