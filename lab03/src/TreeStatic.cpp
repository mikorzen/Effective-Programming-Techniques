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

    parent->addChild(*child);
    NodeStatic* childParent = child->getParent();
    child->setParent(parent);
    
    if (childParent != NULL)
        childParent->removeChild(child);

    return true;
}