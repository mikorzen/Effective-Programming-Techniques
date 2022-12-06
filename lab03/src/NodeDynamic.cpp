#include "NodeDynamic.hpp"
#include <iostream>


NodeDynamic::NodeDynamic() {

    value = 0;
    parent = NULL;
}

NodeDynamic::~NodeDynamic() {

    parent = NULL;

    int childrenNum = getChildrenNum();
    for (int i = 0; i < childrenNum; i++)
        delete children.at(i);

    children.clear();
}

void NodeDynamic::setValue(int value) {

    this->value = value;
}

void NodeDynamic::setParent(NodeDynamic* parent) {

    this->parent = parent;
}

void NodeDynamic::addChild() {

    NodeDynamic* child = new NodeDynamic();
    child->parent = this;
    children.push_back(child);
}

void NodeDynamic::addChild(NodeDynamic* child) {

    child->parent = this;
    children.push_back(child);
}

bool NodeDynamic::removeChild(NodeDynamic* child) {

    int childrenNum = getChildrenNum();
    for (int i = 0; i < childrenNum; i++) {

        NodeDynamic* currChild = children.at(i);
        if (currChild == child) {

            currChild->setParent(NULL);
            children.erase(children.begin() + i);
            return true;
        }
    }
    return false;
}

int NodeDynamic::getValue() {

    return value;
}

NodeDynamic* NodeDynamic::getParent() {

    return parent;
}

int NodeDynamic::getChildrenNum() {

    return children.size();
}

NodeDynamic* NodeDynamic::getChild(int childOffset) {

    if (childOffset < 0 || childOffset >= getChildrenNum())
        return NULL;

    return children.at(childOffset);
}

void NodeDynamic::print() {

    std::cout << " " << value;
}

void NodeDynamic::printBelow() {

    this->print();

    int childrenNum = getChildrenNum();
    for (int i = 0; i < childrenNum; i++)
        children.at(i)->printBelow();
}

void NodeDynamic::printAbove() {

    this->print();
    if (parent != NULL)
        parent->printAbove();
}