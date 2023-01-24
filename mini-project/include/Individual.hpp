#pragma once

#include <vector>
#include <random>
#include <utility>

#include <KnapsackProblem.hpp>


class Individual {

    private:

        int length;
        std::vector<bool> geneticCode;
        double fitness;
        bool recentlyMutated;

        std::random_device rand_device;
        std::default_random_engine generator;
        std::uniform_real_distribution<double> chance;

    public:

        Individual();
        Individual(int length);
        Individual(std::vector<bool>& geneticCode);
        Individual(const Individual& other);
        Individual& operator=(const Individual& other);

        const std::vector<bool>& getGeneticCode() const;
        const double& getFitness() const;

        void evaluate(const KnapsackProblem& problem);
        std::pair<Individual, Individual> crossover(const Individual& other);
        void mutate(double mutationChance);

        void print() const;
        void printGeneticCode() const;
};