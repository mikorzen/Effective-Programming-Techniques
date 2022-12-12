#pragma once

#include <iostream>


template<typename T>
TreeDynamic<T>::TreeDynamic() {

    root = new NodeDynamic<T>();
}

template<typename T>
TreeDynamic<T>::~TreeDynamic() {

    delete root;
}

template<typename T>
NodeDynamic<T>* TreeDynamic<T>::getRoot() {

    return root;
}

template<typename T>
void TreeDynamic<T>::printTree() {

    root->printBelow();
    std::cout << std::endl;
}

template<typename T>
bool TreeDynamic<T>::moveSubtree(NodeDynamic<T>* parent, NodeDynamic<T>* child) {

    if (parent == NULL || child == NULL)
        return false;
    
    NodeDynamic<T>* childParent = child->getParent();
    if (childParent != NULL)
        childParent->removeChild(child);

    parent->addChild(child);
    return true;
}
