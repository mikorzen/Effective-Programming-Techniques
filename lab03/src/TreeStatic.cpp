#include "NodeStatic.hpp"
#include "TreeStatic.hpp"
#include <iostream>


NodeStatic* TreeStatic::getRoot() {

    return &root;
}

void TreeStatic::printTree() {

    root.printAllBelow();
}