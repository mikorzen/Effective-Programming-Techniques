#pragma once
#include "NodeStatic.hpp"


class TreeStatic {

    private:

        NodeStatic root;

    public:

        TreeStatic();
        ~TreeStatic();

        NodeStatic* getRoot();

        void printTree();
};