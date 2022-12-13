#pragma once

#include <iostream>


TreeDynamic<double>::TreeDynamic() {

    root = new NodeDynamic<double>();
}

TreeDynamic<double>::~TreeDynamic() {

    delete root;
}

NodeDynamic<double>* TreeDynamic<double>::getRoot() {

    return root;
}

void TreeDynamic<double>::printTree() {

    root->printBelow();
    std::cout << std::endl;
}

bool TreeDynamic<double>::moveSubtree(NodeDynamic<double>* parent, NodeDynamic<double>* child) {

    if (parent == NULL || child == NULL)
        return false;
    
    NodeDynamic<double>* childParent = child->getParent();
    if (childParent != NULL)
        childParent->removeChild(child);

    parent->addChild(child);
    return true;
}

double TreeDynamic<double>::sumOfValues() const {

    double sum = 0;
    root->sumOfSubtree(sum);
    return sum;
}
