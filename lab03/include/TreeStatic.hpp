#pragma once
#include "NodeStatic.hpp"


class TreeStatic {

    private:

        NodeStatic root;

    public:

        TreeStatic();

        NodeStatic* getRoot();

        void printTree();

        bool moveSubtree(NodeStatic* parent, NodeStatic* child);
};