#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>

#include <KnapsackProblem.hpp>


bool KnapsackProblem::loadItems(const std::string &filepath) {

    std::ifstream file(filepath);
    if (!file.is_open())
        return false;

    std::string line;
    file >> line;
    if ((capacity = std::stod(line)) <= 0)
        throw std::runtime_error("Invalid value of 'capacity' encountered (must be greater than 0).");

    double weight;
    double value;
    for (int i = 0; file >> line; i++) {
        if (i % 2 == 0) {
            if ((value = std::stod(line)) < 0)
                throw std::runtime_error("Invalid value of 'value' encountered (must be no less than 0).");
            values.push_back(value);
        } else {
            if ((weight = std::stod(line)) <= 0)
                throw std::runtime_error("Invalid value of 'weight' encountered (must be greater than 0).");
            weights.push_back(weight);
        }
    }

    if (weights.size() != values.size()) {
        std::string message = 
            "There is a mismatch between the number of item weights and the number of item values provided.";
        throw std::runtime_error(message);
    }

    if ((itemCount = values.size()) <= 0)
        throw std::runtime_error("Invalid value of 'item count' encountered (must be greater than 0).");

    return true;
}

double KnapsackProblem::getCapacity() const {
    return capacity;
}

int KnapsackProblem::getItemCount() const {
    return itemCount;
}

std::vector<double> KnapsackProblem::getWeights() const {
    return weights;
}

std::vector<double> KnapsackProblem::getValues() const {
    return values;
}

double KnapsackProblem::evaluate(const std::vector<bool>& geneticCode) const {

    double totalWeight = 0;
    double totalValue = 0;
    for (int i = 0; i < itemCount; i++)
        if (geneticCode[i]) {
            totalWeight += weights[i];
            totalValue += values[i];
        }

    if (totalWeight > capacity)
        return 0;

    return totalValue;
}

void KnapsackProblem::print() const {

    std::cout << "Problem properties:" << std::endl;

    std::cout << "\tCapacity: " << capacity << std::endl;
    std::cout << "\tItem details:" << std::endl;

    std::cout << "\tLp.\tValue\t\tWeight" << std::endl;
    for (int i = 0; i < itemCount; i++)
        printItem(i);
    std::cout << std::endl;
}

void KnapsackProblem::printItem(int index) const {
    
    std::cout << "\t" << index + 1 << ".";
    std::cout << "\t" << values[index];
    std::cout << "\t\t" << weights[index] << std::endl;
}
