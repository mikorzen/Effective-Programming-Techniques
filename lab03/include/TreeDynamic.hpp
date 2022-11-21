#pragma once
#include "NodeDynamic.hpp"


class TreeDynamic {

    private:

        NodeDynamic* root;

    public:

        TreeDynamic();
        ~TreeDynamic();

        NodeDynamic* getRoot();

        void printTree();

        bool moveSubtree(NodeDynamic* parent, NodeDynamic* child);
};