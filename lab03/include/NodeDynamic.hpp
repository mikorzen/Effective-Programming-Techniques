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
        void setParent(NodeDynamic* parent);
        void addChild();
        void addChild(NodeDynamic* child);
        bool removeChild(NodeDynamic* child);

        int getValue();
        NodeDynamic* getParent();
        int getChildrenNum();
        NodeDynamic* getChild(int childOffset);

        void print();
        void printBelow();
        void printAbove();
};