#include "NodeDynamic.hpp"
#include "TreeDynamic.hpp"
#include <iostream>


TreeDynamic::TreeDynamic() {

    root = new NodeDynamic();
}

TreeDynamic::~TreeDynamic() {

    delete root;
}

NodeDynamic* TreeDynamic::getRoot() {

    return root;
}

void TreeDynamic::printTree() {

    root->printBelow();
    std::cout << std::endl;
}

bool TreeDynamic::moveSubtree(NodeDynamic* parent, NodeDynamic* child) {

    if (parent == NULL || child == NULL)
        return false;
    
    NodeDynamic* childParent = child->getParent();
    if (childParent != NULL)
        childParent->removeChild(child);

    parent->addChild(child);
    return true;
}