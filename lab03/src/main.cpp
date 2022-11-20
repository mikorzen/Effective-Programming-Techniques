#include "NodeStatic.hpp"
#include "TreeStatic.hpp"
#include <iostream>


int main() {

    NodeStatic root;

    root.addChild();
    root.addChild();
    root.getChild(0)->setValue(1);
    root.getChild(1)->setValue(2);

    root.getChild(0)->addChild();
    root.getChild(0)->addChild();
    root.getChild(0)->getChild(0)->setValue(11);
    root.getChild(0)->getChild(1)->setValue(12);

    root.getChild(1)->addChild();
    root.getChild(1)->addChild();
    root.getChild(1)->getChild(0)->setValue(21);
    root.getChild(1)->getChild(1)->setValue(22);

    root.printBelow();

    std::cout << std::endl;;
    std::cout << std::endl;;

    root.getChild(0)->getChild(1)->printAbove();

    std::cout << std::endl;;
}
