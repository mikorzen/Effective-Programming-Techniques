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

        void setValue(T value);
        void setParent(NodeDynamic<T>* parent);
        void addChild();
        void addChild(NodeDynamic<T>* child);
        bool removeChild(NodeDynamic<T>* child);

        T getValue();
        NodeDynamic<T>* getParent();
        int getChildrenNum();
        std::vector<NodeDynamic<T>*> getChildren();
        NodeDynamic<T>* getChild(int childOffset);

        void print();
        void printBelow();
        void printAbove();

};

template< >
class NodeDynamic<double> {

    private:

        NodeDynamic<double>* parent;
        std::vector<NodeDynamic<double>*> children;
        double value;

    public:

        NodeDynamic();
        ~NodeDynamic();

        void setValue(double value);
        void setParent(NodeDynamic<double>* parent);
        void addChild();
        void addChild(NodeDynamic<double>* child);
        bool removeChild(NodeDynamic<double>* child);

        double getValue();
        NodeDynamic<double>* getParent();
        int getChildrenNum();
        std::vector<NodeDynamic<double>*> getChildren();
        NodeDynamic<double>* getChild(int childOffset);

        void print();
        void printBelow();
        void printAbove();

        void sumOfSubtree(double& sum);
};


#include <NodeDynamic.tpp>
#include <NodeDynamicDouble.tpp>
