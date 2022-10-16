#include <iostream>
#include <string>

class Table {

    private:

        const std::string defaultName = "Tablica";
        const int defaultarrayLen = 5;

        std::string name;
        int arrayLen;

        int *array;


    public:

        Table() {

            name = defaultName;
            arrayLen = defaultarrayLen;
            array = new int[arrayLen];

            std::cout << "bezp: '" << name << "'" << std::endl;
        };

        Table(std::string name, int arrayLen) {

            this->name = name;
            this->arrayLen = arrayLen;
            array = new int[arrayLen];

            std::cout << "param: '" << name << "'" << std::endl;
        };

        Table(const Table &otherTable) {

            name = otherTable.name + "_copy";
            arrayLen = otherTable.arrayLen;
            array = new int[arrayLen];

            for (int i = 0; i < arrayLen; i++)
                array[i] = otherTable.array[i];

            std::cout << "kopiuj: '" << name << "'" << std::endl;
        }

        Table *clone() {
            
            return new Table(*this);
        }

        ~Table() {

            delete[] array;
            std::cout << "usuwam: '" << name << "'" << std::endl;
        }

        void setName(std::string name) {

            this->name = name;
        }

        bool setArrayLen(int arrayLen) {

            if (arrayLen <= 0)
                return false;

            this->arrayLen = arrayLen;
            int *temp = new int[arrayLen];

            for (int i = 0; i < arrayLen; i++)
                temp[i] = array[i];
            
            delete[] array;
            array = temp;

            return true;
        }

        void printTable() {

            for (int i = 0; i < arrayLen; i++)
                std::cout << name << "[" << i << "] = " << array[i] << std::endl;
        }
};


void modTable(Table table, int arrayLen) {

    table.setArrayLen(arrayLen);
}

void modTable(Table *table, int arrayLen) {

    table->setArrayLen(arrayLen);
}


int main() {

    Table tablica = Table();
    Table *tablicaClone = tablica.clone();
    tablica.printTable();
    std::cout << std::endl;
    tablicaClone->printTable();
    std::cout << std::endl;

    modTable(tablica, 3);
    tablica.printTable();
    std::cout << std::endl;

    modTable(tablicaClone, 3);
    tablicaClone->printTable();
    std::cout << std::endl;
    return 0;
}