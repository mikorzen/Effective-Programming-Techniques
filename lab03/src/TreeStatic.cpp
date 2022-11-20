#include "NodeStatic.hpp"
#include "TreeStatic.hpp"
#include <iostream>


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
    if (childParent != NULL)
        childParent->removeChild(child);

    child->setParent(parent);
    return true;
}