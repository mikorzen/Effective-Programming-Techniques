#include <iostream>
#include <string>

class Table {

    private:

        const std::string default_name = "Tablica";
        const int default_array_len = 5;

        std::string name;
        int array_len;

        int *array;


    public:

        Table() {

            name = default_name;
            array_len = default_array_len;
            array = new int[array_len];

            std::cout << "bezp: '" << name << "'" << std::endl;
        };

        Table(std::string name, int arrayLen) {

            this->name = name;
            this->array_len = array_len;
            array = new int[array_len];

            std::cout << "param: '" << name << "'" << std::endl;
        };

        Table(const Table &otherTable) {

            name = otherTable.name + "_copy";
            array_len = otherTable.array_len;
            array = new int[array_len];

            for (int i = 0; i < array_len; i++)
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

        bool setArrayLen(int array_len) {

            if (array_len <= 0)
                return false;

            this->array_len = array_len;
            int *temp = new int[array_len];

            for (int i = 0; i < array_len; i++)
                temp[i] = array[i];
            
            delete[] array;
            array = temp;

            return true;
        }

        void printTable() {

            for (int i = 0; i < array_len; i++)
                std::cout << name << "[" << i << "] = " << array[i] << std::endl;
        }
};


void modTable(Table table, int array_len) {

    table.setArrayLen(array_len);
}

void modTable(Table *table, int array_len) {

    table->setArrayLen(array_len);
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