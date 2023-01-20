#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>

#include <KnapsackProblem.hpp>


KnapsackProblem::KnapsackProblem() {

    this->capacity = 5;
    this->itemCount = 5;
}

KnapsackProblem::KnapsackProblem(int capacity, int itemCount) {

    if (capacity < 0)
        throw std::invalid_argument("Capacity must be greater than 0");
    this->capacity = capacity;

    if (itemCount < 0)
        throw std::invalid_argument("Item count must be greater than 0");
    this->itemCount = itemCount;
}

bool KnapsackProblem::loadItems(const std::string &filepath) {

    std::ifstream file(filepath);
    
    if (!file.is_open())
        std::cout << "Failed to access file" << std::endl;
        return false;

    int itemCount;
    std::vector<double> weights;
    std::vector<double> values;

    std::string line;
    for (int i = 0; file >> line; i++) {

    }
}
