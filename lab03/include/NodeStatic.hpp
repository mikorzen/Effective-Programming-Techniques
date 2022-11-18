#pragma once
#include <vector>


class NodeStatic { 

    private:

        NodeStatic* parent;
        std::vector<NodeStatic> children;
        int value;

    public:

        NodeStatic();
        ~NodeStatic();

        void setValue(int value);

        int getChildrenNum();
        void addChild();
        NodeStatic* getChild(int childOffset);

        void print();
        void printAllBelow();
        void printAllAbove();
};