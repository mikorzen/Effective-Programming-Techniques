#include <iostream>

#include <KnapsackProblem.hpp>
#include <GeneticAlgorithm.hpp>


int main() {

    KnapsackProblem problem;
    std::string filepath = "../data/f6_l-d_kp_10_60";

    try {
        while(!problem.loadItems(filepath)) {
            std::cout << "Failed to access file: " << filepath << std::endl;
            std::cout << "Do you wish to try again with the same file? (Y/N): ";
            std::string response;
            std::cin >> response;

            if (response == "N" || response == "n") {
                std::cout << "Enter the path to a valid and accessible file: ";
                std::cin >> filepath;
            }
        }
        std::cout << "Items sucessfuly loaded." << std::endl << std::endl;
    } 
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        std::cout << "Please verify the validity of input data before trying again." << std::endl;
        return 1;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "An error occured regarding input data (eg. it being of an invalid format)." << std::endl;
        std::cout << "Please verify the validity of input data before trying again." << std::endl;
        return 1;
    }

    problem.print();

    int iterations = 100;
    int populationSize = 10;
    double mutationChance = 0.1;
    double crossoverChance = 0.6;

    GeneticAlgorithm algorithm(problem, iterations, populationSize, mutationChance, crossoverChance);
    algorithm.run();
}