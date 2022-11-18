#pragma once
#include <vector>


class NodeDynamic { 

    private:

        NodeDynamic* parent;
        std::vector<NodeDynamic*> children;
        int value;

    public:

        NodeDynamic();
        ~NodeDynamic();

        void setValue(int value);

        int getChildrenNum();
        void addChild();
        NodeDynamic* getChild(int childOffset);

        void print();
        void printAllBelow();
        void printAllAbove();
};