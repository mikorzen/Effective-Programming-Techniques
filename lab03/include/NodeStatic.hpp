#pragma once
#include <vector>


class NodeStatic { 

    private:

        NodeStatic* parent;
        std::vector<NodeStatic> children;
        int value;

    public:

        NodeStatic();

        void setValue(int value);
        void setParent(NodeStatic* parent);
        void addChild();
        void addChild(NodeStatic* child);
        void removeChild(NodeStatic* child);

        int getValue() const;
        NodeStatic* getParent() const;
        int getChildrenNum() const;
        NodeStatic* getChild(int childOffset);

        void print();
        void printBelow();
        void printAbove();

        bool operator==(NodeStatic& other);
        bool isInSubtree(const NodeStatic& other) const;
        bool isRelatedTo(const NodeStatic& other) const;
};