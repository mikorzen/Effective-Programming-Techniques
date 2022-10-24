#include "arrays.hpp"
#include <iostream>


void alloc_array_fill(int size, int filler) {

    while (size <= 0) {
        std::cout << "Nieprawidłowy rozmiar tablicy." << std::endl;
        return;
    }

    int* array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = filler;

    for (int i = 0; i < size; i++)
        std::cout << "array[" << i << "] = " << array[i] << std::endl;

    delete[] array;
}

bool alloc_array_2D(int*** array, int sizeX, int sizeY) {

    if (sizeX <= 0 || sizeY <= 0) {
        std::cout << "Nieprawidłowy rozmiar tablicy." << std::endl;
        return false;
    }

    *array = new int*[sizeX];
    for (int i = 0; i < sizeX; i++)
        (*array)[i] = new int[sizeY];

    return true;
}

bool dealloc_array_2D(int*** array, int sizeX) {

    if (sizeX <= 0) {
        std::cout << "Podano nieprawidłowy rozmiar." << std::endl;
        return false;
    }

    for (int i = 0; i < sizeX; i++)
        delete[] (*array)[i];
    
    delete[] *array;
    return true;
}


int main() {

    alloc_array_fill(5, 34);

    int** array;
    bool canDealloc = alloc_array_2D(&array, 5, 3);
    if (canDealloc) dealloc_array_2D(&array, 5);

    return 0;
}