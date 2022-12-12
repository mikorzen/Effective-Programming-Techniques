#pragma once

#include <vector>


template<typename T> 
class NodeDynamic { 

    private:

        NodeDynamic<T>* parent;
        std::vector<NodeDynamic<T>*> children;
        T value;

    public:

        NodeDynamic();
        ~NodeDynamic();

        void setValue(int value);
        void setParent(NodeDynamic<T>* parent);
        void addChild();
        void addChild(NodeDynamic<T>* child);
        bool removeChild(NodeDynamic<T>* child);

        T getValue();
        NodeDynamic<T>* getParent();
        int getChildrenNum();
        NodeDynamic<T>* getChild(int childOffset);

        void print();
        void printBelow();
        void printAbove();
};


#include <NodeDynamic.tpp>