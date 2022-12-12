#pragma once

#include "NodeDynamic.hpp"


template<typename T>
class TreeDynamic {

    private:

        NodeDynamic<T>* root;

    public:

        TreeDynamic();
        ~TreeDynamic();

        NodeDynamic<T>* getRoot();

        void printTree();

        bool moveSubtree(NodeDynamic<T>* parent, NodeDynamic<T>* child);
};


#include <TreeDynamic.tpp>