#include <vector>
#include <random>
#include <utility>
#include <iostream>

#include <Individual.hpp>
#include <KnapsackProblem.hpp>


Individual::Individual() {

    recentlyMutated = true;

    generator = std::default_random_engine(rand_device());
    chance = std::uniform_real_distribution<double>(0.0, 1.0);
}

Individual::Individual(int length) : Individual() {

    this->length = length;
    for (int i = 0; i < length; i++)
        geneticCode.push_back(chance(generator) < 0.5);
}

Individual::Individual(const std::vector<bool>& geneticCode) : Individual() {

    length = geneticCode.size();
    this->geneticCode = geneticCode;
}

Individual::Individual(const Individual& other) : Individual() {

    length = other.length;
    geneticCode = other.geneticCode;
    fitness = other.fitness;
    recentlyMutated = other.recentlyMutated;
}

Individual& Individual::operator=(const Individual& other) {

    length = other.length;
    geneticCode = other.geneticCode;
    fitness = other.fitness;
    recentlyMutated = other.recentlyMutated;

    return *this;
}

const std::vector<bool>& Individual::getGeneticCode() const {
    return geneticCode;
}

const double& Individual::getFitness() const {
    return fitness;
}

void Individual::evaluate(const KnapsackProblem& problem) {

    if (recentlyMutated) {
        fitness = problem.evaluate(geneticCode); 
        recentlyMutated = false;
    }
}

std::pair<Individual, Individual> Individual::crossover(const Individual& other) {

    std::vector<bool> child1 = std::vector<bool>(length);
    std::vector<bool> child2 = std::vector<bool>(length);

    for (int i = 0; i < length; i++) {
        if (chance(generator) < 0.5) {
            child1[i] = geneticCode[i];
            child2[i] = other.geneticCode[i];
        } else {
            child1[i] = other.geneticCode[i];
            child2[i] = geneticCode[i];
        }
    }
    return std::make_pair(Individual(child1), Individual(child2));
}

void Individual::mutate(double mutationChance) {

    for (int i = 0; i < length; i++)
        if (chance(generator) < mutationChance) {
            geneticCode[i] = !geneticCode[i];
            recentlyMutated = true;
        }
}

void Individual::print() const {

    std::cout << "\t"; printGeneticCode();
    std::cout << "\t\t" << fitness << std::endl;
}

void Individual::printGeneticCode() const {

    for (int i = 0; i < length; i++)
        std::cout << geneticCode[i];
}
