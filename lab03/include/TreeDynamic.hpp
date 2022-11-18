#pragma once
#include "NodeDynamic.hpp"


class TreeDynamic {

    private:

        NodeDynamic* root;

    public:

        TreeDynamic();
        ~TreeDynamic();

        TreeDynamic* getRoot();

        void printTree();
};