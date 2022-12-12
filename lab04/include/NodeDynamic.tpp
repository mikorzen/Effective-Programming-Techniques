#pragma once

#include <iostream>
#include <vector>


template<typename T> 
NodeDynamic<T>::NodeDynamic() {

    value = 0;
    parent = NULL;
}

template<typename T> 
NodeDynamic<T>::~NodeDynamic() {

    parent = NULL;

    int childrenNum = getChildrenNum();
    for (int i = 0; i < childrenNum; i++)
        delete children.at(i);

    children.clear();
}

template<typename T> 
void NodeDynamic<T>::setValue(int value) {

    this->value = value;
}

template<typename T> 
void NodeDynamic<T>::setParent(NodeDynamic<T>* parent) {
    
    this->parent = parent;
}

template<typename T> 
void NodeDynamic<T>::addChild() {

    NodeDynamic<T>* child = new NodeDynamic<T>();
    child->parent = this;
    children.push_back(child);
}

template<typename T> 
void NodeDynamic<T>::addChild(NodeDynamic<T>* child) {

    child->parent = this;
    children.push_back(child);
}

template<typename T> 
bool NodeDynamic<T>::removeChild(NodeDynamic<T>* child) {

    int childrenNum = getChildrenNum();
    for (int i = 0; i < childrenNum; i++) {

        NodeDynamic<T>* currChild = children.at(i);
        if (currChild == child) {

            currChild->setParent(NULL);
            children.erase(children.begin() + i);
            return true;
        }
    }
    return false;
}

template<typename T> 
T NodeDynamic<T>::getValue() {

    return value;
}

template<typename T> 
NodeDynamic<T>* NodeDynamic<T>::getParent() {

    return parent;
}

template<typename T> 
int NodeDynamic<T>::getChildrenNum() {

    return children.size();
}

template<typename T> 
NodeDynamic<T>* NodeDynamic<T>::getChild(int childOffset) {

    if (childOffset < 0 || childOffset >= getChildrenNum())
        return NULL;

    return children.at(childOffset);
}

template<typename T> 
void NodeDynamic<T>::print() {

    std::cout << " " << value;
}

template<typename T> 
void NodeDynamic<T>::printBelow() {

    this->print();

    int childrenNum = getChildrenNum();
    for (int i = 0; i < childrenNum; i++)
        children.at(i)->printBelow();
}

template<typename T> 
void NodeDynamic<T>::printAbove() {

    this->print();
    if (parent != NULL)
        parent->printAbove();
}
