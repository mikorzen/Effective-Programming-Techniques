#pragma once

#include <vector>

#include <Individual.hpp>
#include <KnapsackProblem.hpp>


class GeneticAlgorithm {

    private:

        KnapsackProblem problem;
        int iterations;
        int populationSize;
        double mutationChance;
        double crossoverChance;

        std::random_device rand_device;
        std::default_random_engine generator;
        std::uniform_real_distribution<double> chance;
        std::uniform_int_distribution<int> index;

        std::vector<Individual> population;
        
        int bestIteration;
        std::vector<Individual> bestPopulation;
        int bestIndex;
        Individual bestIndividual;

        void initializePopulation(int length);
        void evaluatePopulation(int iteration);
        void crossoverPopulation();
        void mutatePopulation();

        std::string chooseSuffix(int number) const;

    public:

        GeneticAlgorithm() = delete;
        GeneticAlgorithm(KnapsackProblem& problem, 
                         int iterations, 
                         int populationSize, 
                         double mutationChance, 
                         double crossoverChance);

        const std::vector<Individual>& getPopulation() const;

        const int& getBestIteration() const;
        const std::vector<Individual>& getBestPopulation() const;
        const int& getBestIndex() const;
        const Individual& getBestIndividual() const;

        void run();
        void printBestPopulation() const;
        void printBestIndividual() const;
};