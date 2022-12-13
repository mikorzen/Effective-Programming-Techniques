#pragma once

#include <iostream>
#include <vector>


NodeDynamic<double>::NodeDynamic() {

    value = 0.0;
    parent = NULL;
}

NodeDynamic<double>::~NodeDynamic() {

    parent = NULL;

    int childrenNum = getChildrenNum();
    for (int i = 0; i < childrenNum; i++)
        delete children[i];

    children.clear();
}

void NodeDynamic<double>::setValue(double value) {

    this->value = value;
}

void NodeDynamic<double>::setParent(NodeDynamic<double>* parent) {
    
    this->parent = parent;
}

void NodeDynamic<double>::addChild() {

    NodeDynamic<double>* child = new NodeDynamic<double>();
    child->parent = this;
    children.push_back(child);
}

void NodeDynamic<double>::addChild(NodeDynamic<double>* child) {

    child->parent = this;
    children.push_back(child);
}

bool NodeDynamic<double>::removeChild(NodeDynamic<double>* child) {

    int childrenNum = getChildrenNum();
    for (int i = 0; i < childrenNum; i++) {

        NodeDynamic<double>* currChild = children[i];
        if (currChild == child) {

            currChild->setParent(NULL);
            children.erase(children.begin() + i);
            return true;
        }
    }
    return false;
}

double NodeDynamic<double>::getValue() {

    return value;
}

NodeDynamic<double>* NodeDynamic<double>::getParent() {

    return parent;
}

int NodeDynamic<double>::getChildrenNum() {

    return children.size();
}

std::vector<NodeDynamic<double>*> NodeDynamic<double>::getChildren() {

    return children;
}

NodeDynamic<double>* NodeDynamic<double>::getChild(int childOffset) {

    if (childOffset < 0 || childOffset >= getChildrenNum())
        return NULL;

    return children[childOffset];
}

void NodeDynamic<double>::print() {

    std::cout << " " << value;
}

void NodeDynamic<double>::printBelow() {

    this->print();

    int childrenNum = getChildrenNum();
    for (int i = 0; i < childrenNum; i++)
        children[i]->printBelow();
}

void NodeDynamic<double>::printAbove() {

    this->print();
    if (parent != NULL)
        parent->printAbove();
}

void NodeDynamic<double>::sumOfSubtree(double& sum) {

    sum += getValue();

    if(getChildrenNum() <= 0)
        return;

    std::vector<NodeDynamic<double>*> children = getChildren();
    for(int i = 0; i < children.size(); i++) {
        
        children[i]->sumOfSubtree(sum);
    }
}
