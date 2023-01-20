#pragma once

#include <string>
#include <vector>


class KnapsackProblem {

    private:

        int capacity;
        int itemCount;
        std::vector<double> weights;
        std::vector<double> values;

    public:

        KnapsackProblem();
        KnapsackProblem(int capacity, int itemCount);
        ~KnapsackProblem();

        int getCapacity() const;
        int getItemCount() const;
        int *getWeights() const;
        int *getValues() const;

        bool loadItems(const std::string &filepath);
};
