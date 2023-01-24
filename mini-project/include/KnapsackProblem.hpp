#pragma once

#include <string>
#include <vector>


class KnapsackProblem {

    private:

        double capacity;
        int itemCount;
        std::vector<double> weights;
        std::vector<double> values;

    public:

        KnapsackProblem();
        KnapsackProblem(double capacity);

        bool addItem(double weight, double value);
        bool loadItemsFromFile(const std::string &filepath);

        double getCapacity() const;
        int getItemCount() const;
        std::vector<double> getWeights() const;
        std::vector<double> getValues() const;

        bool setCapacity(double capacity);

        double evaluate(const std::vector<bool>& geneticCode) const;

        void print() const;
        void printItem(int index) const;    
};
