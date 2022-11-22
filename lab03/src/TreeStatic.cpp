#include "NodeStatic.hpp"
#include "TreeStatic.hpp"
#include <iostream>


TreeStatic::TreeStatic() {

    root = NodeStatic();
}

NodeStatic* TreeStatic::getRoot() {

    return &root;
}

void TreeStatic::printTree() {

    root.printBelow();
    std::cout << std::endl;
}

bool TreeStatic::moveSubtree(NodeStatic* parent, NodeStatic* child) {

    if (parent == NULL || child == NULL)
        return false;

    NodeStatic* childParent = child->getParent();
    parent->addChild(child);

    if (childParent != NULL)
        childParent->removeChild(child);

    return true;
}
