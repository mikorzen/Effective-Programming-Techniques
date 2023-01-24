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

        bool loadItems(const std::string &filepath);

        double getCapacity() const;
        int getItemCount() const;
        std::vector<double> getWeights() const;
        std::vector<double> getValues() const;

        double evaluate(const std::vector<bool>& geneticCode) const;

        void print() const;
        void printItem(int index) const;    
};
