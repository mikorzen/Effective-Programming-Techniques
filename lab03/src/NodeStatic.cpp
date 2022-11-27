#include "NodeStatic.hpp"
#include <iostream>


NodeStatic::NodeStatic() {

    value = 0;
    parent = NULL;
}

NodeStatic::NodeStatic(NodeStatic& other) {

    value = other.value;
    parent = other.parent;
    children = other.children;
}

NodeStatic::~NodeStatic() {

    parent = NULL;
    children.clear();
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

void NodeStatic::addChild(NodeStatic* child) {

    child->parent = this;
    children.push_back(*child);
}

bool NodeStatic::removeChild(NodeStatic* child) {

    int childrenNum = getChildrenNum();
    for (int i = 0; i < childrenNum; i++) {

        NodeStatic* currChild = &children.at(i);
        if (currChild == child) {

            currChild->setParent(NULL);
            children.erase(children.begin() + i);
            return true;
        }
    }
    return false;
}

int NodeStatic::getValue() const {

    return value;
}

NodeStatic* NodeStatic::getParent() const {

    return parent;
}

int NodeStatic::getChildrenNum() const {

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

    print();

    int childrenNum = getChildrenNum();
    for (int i = 0; i < childrenNum; i++)
        children.at(i).printBelow();
}

void NodeStatic::printAbove() {

    print();
    if (parent != NULL)
        parent->printAbove();
}

bool NodeStatic::isInSubtree(const NodeStatic& other) const {

    if (this == &other)
        return true;

    NodeStatic* currParent = other.parent;
    while (this != currParent) {

        if (currParent == NULL) 
            return false;
        currParent = currParent->parent;
    }

    return true;
}

bool NodeStatic::isRelatedTo(const NodeStatic& other) const {

    return isInSubtree(other) || other.isInSubtree(*this);
}