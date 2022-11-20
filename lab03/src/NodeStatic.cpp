#include "NodeStatic.hpp"
#include <iostream>


NodeStatic::NodeStatic() {

    value = 0;
    parent = NULL;
}

void NodeStatic::setValue(int value) {

    this->value = value;
}

void NodeStatic::setParent(NodeStatic* parent) {

    this->parent = parent;
}

void NodeStatic::addChild() {

    NodeStatic child;
    child.parent = this;
    children.push_back(child);
}

void NodeStatic::addChild(NodeStatic child) {

    child.parent = this;
    children.push_back(child);
}

void NodeStatic::removeChild(NodeStatic* child) {

    int childrenNum = getChildrenNum();
    for (int i = 0; i < childrenNum; i++) {

        NodeStatic* currChild = &children.at(i);
        if (currChild == child) {

            currChild->setParent(NULL);
            children.erase(children.begin() + i);
        }
    }
}

int NodeStatic::getValue() {

    return value;
}

NodeStatic* NodeStatic::getParent() {

    return parent;
}

int NodeStatic::getChildrenNum() {

    return children.size();
}

NodeStatic* NodeStatic::getChild(int childOffset) {

    if (childOffset < 0 || childOffset >= getChildrenNum())
        return NULL;

    return &children.at(childOffset);
}

void NodeStatic::print() {

    std::cout << " " << value;
}

void NodeStatic::printBelow() {

    this->print();

    int childrenNum = getChildrenNum();
    for (int i = 0; i < childrenNum; i++)
        children.at(i).printBelow();
}

void NodeStatic::printAbove() {

    this->print();
    if (parent != NULL)
        parent->printAbove();
}