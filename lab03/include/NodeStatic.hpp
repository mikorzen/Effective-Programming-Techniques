#pragma once
#include <vector>


class NodeStatic { 

    private:

        NodeStatic* parent;
        std::vector<NodeStatic> children;
        int value;

    public:

        NodeStatic();
        NodeStatic(NodeStatic& other);
        ~NodeStatic();

        void setValue(int value);
        void setParent(NodeStatic* parent);
        void addChild();
        void addChild(NodeStatic* child);
        bool removeChild(NodeStatic* child);

        int getValue() const;
        NodeStatic* getParent() const;
        int getChildrenNum() const;
        NodeStatic* getChild(int childOffset);

        void print();
        void printBelow();
        void printAbove();

        bool isInSubtree(const NodeStatic& other) const;
        bool isRelatedTo(const NodeStatic& other) const;
};