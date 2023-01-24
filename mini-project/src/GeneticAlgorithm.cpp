#include <vector>
#include <algorithm>
#include <iostream>

#include <Individual.hpp>
#include <GeneticAlgorithm.hpp>
#include <KnapsackProblem.hpp>


GeneticAlgorithm::GeneticAlgorithm(KnapsackProblem& problem, 
                                   int iterations, 
                                   int populationSize, 
                                   double mutationChance, 
                                   double crossoverChance) {

    this->problem = problem;
    this->iterations = iterations;
    this->populationSize = populationSize;
    this->mutationChance = mutationChance;
    this->crossoverChance = crossoverChance;

    generator = std::default_random_engine(rand_device());
    chance = std::uniform_real_distribution<double>(0.0, 1.0);
    index = std::uniform_int_distribution<int>(0, populationSize - 1);
}

const std::vector<Individual>& GeneticAlgorithm::getPopulation() const {
    return population;
}

const int& GeneticAlgorithm::getBestIteration() const {
    return bestIteration;
}

const std::vector<Individual>& GeneticAlgorithm::getBestPopulation() const {
    return bestPopulation;
}

const int& GeneticAlgorithm::getBestIndex() const {
    return bestIndex;
}

const Individual& GeneticAlgorithm::getBestIndividual() const {
    return bestIndividual;
}

void GeneticAlgorithm::initializePopulation(int length) {

    for (int i = 0; i < populationSize; i++)
        population.push_back(Individual(length));

    bestIteration = 1;
    bestPopulation = population;

    bestIndex = 1;
    bestIndividual = population[0];
}

void GeneticAlgorithm::evaluatePopulation(int iteration) {

    bool foundBest = false;

    for (int i = 0; i < populationSize; i++) {
        population[i].evaluate(problem);
        if (population[i].getFitness() > bestIndividual.getFitness()) {
            foundBest = true;
            bestIndex = i + 1;
            bestIndividual = population[i];
        }
    } if (foundBest) {
        bestIteration = iteration + 1; 
        bestPopulation = population;
    }
}

void GeneticAlgorithm::crossoverPopulation() {

    std::vector<Individual> newPopulation;
    for (int i = 0; i < populationSize; i += 2) {

        Individual indv1 = population[index(generator)];
        Individual indv2 = population[index(generator)];

        if (chance(generator) < crossoverChance) {
            std::pair<Individual, Individual> children = indv1.crossover(indv2);
            indv1 = children.first;
            indv2 = children.second;
        }
        newPopulation.push_back(indv1);
        if (i + 1 < populationSize)
            newPopulation.push_back(indv2);
    }
    population = newPopulation;
}

void GeneticAlgorithm::mutatePopulation() {

    for (Individual& indv : population)
        if (chance(generator) < mutationChance)
            indv.mutate(mutationChance);
}

void GeneticAlgorithm::run() {

    initializePopulation(problem.getItemCount());
    for (int i = 0; i < iterations; i++) {
        evaluatePopulation(i);
        crossoverPopulation();
        mutatePopulation();
    }
    evaluatePopulation(iterations);

    printBestPopulation();
    printBestIndividual();
}

void GeneticAlgorithm::printBestPopulation() const {

    std::cout << "Population the best individual comes from (" << bestIteration << chooseSuffix(bestIteration);
    std::cout << " out of " << iterations << " different populations): " << std::endl; 
    
    std::cout << "\tLp.\tGenetic code\t\tFitness" << std::endl;
    for (int i = 0; i < populationSize; i++) {
        std::cout << "\t" << i + 1 << ".";
        bestPopulation[i].print();
    }
    std::cout << std::endl;
}

void GeneticAlgorithm::printBestIndividual() const {

    std::cout << "Properties of the best individual (" << bestIndex << chooseSuffix(bestIndex);
    std::cout << " out of " << populationSize << " in a population): " << std::endl;
    std::cout << "\tGenetic code:  "; bestIndividual.printGeneticCode();
    std::cout << std::endl;
    std::cout << "\tFitness value: " << bestIndividual.getFitness() << std::endl;
    std::cout << std::endl;
}

std::string GeneticAlgorithm::chooseSuffix(int number) const {

    std::string suffix = "th";
    switch (number % 10) {
        case 1: suffix = "st"; break;
        case 2: suffix = "nd"; break;
        case 3: suffix = "rd"; break;
    }
    return suffix;
}