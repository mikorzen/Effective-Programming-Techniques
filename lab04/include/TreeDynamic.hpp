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

template< >
class TreeDynamic<double> {

    private:

        NodeDynamic<double>* root;

    public:

        TreeDynamic();
        ~TreeDynamic();

        NodeDynamic<double>* getRoot();

        void printTree();

        bool moveSubtree(NodeDynamic<double>* parent, NodeDynamic<double>* child);

        double sumOfValues() const;
};


#include <TreeDynamic.tpp>
#include <TreeDynamicDouble.tpp>
