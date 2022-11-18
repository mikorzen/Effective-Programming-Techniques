#include "NodeStatic.hpp"
#include <iostream>


NodeStatic::NodeStatic() {

    value = 0;
    parent = nullptr;
}

void NodeStatic::setValue(int value) {

    this->value = value;
}

int NodeStatic::getChildrenNum() {

    return children.size();
}

void NodeStatic::addChild() {

    children.push_back(NodeStatic());
}

NodeStatic* NodeStatic::getChild(int childOffset) {

    if (childOffset < 0 || childOffset >= getChildrenNum())
        return NULL;

    return &children.at(childOffset);
}

void NodeStatic::print() {

    std::cout << " " << value;
}

void NodeStatic::printAllBelow() {

    this->print();

    int childrenNum = getChildrenNum();
    for (int i = 0; i < childrenNum; i++)
        children.at(i).printAllBelow();
}

void NodeStatic::printAllAbove() {

    this->print();
    parent->printAllAbove();
}