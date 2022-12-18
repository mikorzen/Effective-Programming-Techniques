#include "NodeDynamic.hpp"
#include "TreeDynamic.hpp"

#include <iostream>


TreeDynamic<int> createTree1() {

    TreeDynamic<int> tree;
    NodeDynamic<int>* root = tree.getRoot();

    root->setValue(0);

    root->addChild();
    root->addChild();
    root->addChild();
    root->getChild(0)->setValue(1);
    root->getChild(1)->setValue(2);
    root->getChild(2)->setValue(3);

    root->getChild(2)->addChild();
    root->getChild(2)->getChild(0)->setValue(4);

    root->getChild(2)->getChild(0)->addChild();
    root->getChild(2)->getChild(0)->getChild(0)->setValue(5);

    return tree;
}

TreeDynamic<int> createTree2() {

    TreeDynamic<int> tree;
    NodeDynamic<int>* root = tree.getRoot();

    root->setValue(50);

    root->addChild();
    root->addChild();
    root->getChild(0)->setValue(54);
    root->getChild(1)->setValue(55);

    root->getChild(0)->addChild();
    root->getChild(0)->addChild();
    root->getChild(0)->getChild(0)->setValue(56);
    root->getChild(0)->getChild(1)->setValue(57);

    root->getChild(0)->getChild(0)->addChild();
    root->getChild(0)->getChild(0)->getChild(0)->setValue(58);

    return tree;
}

TreeDynamic<std::string> createTree3() {

    TreeDynamic<std::string> tree;
    NodeDynamic<std::string>* root = tree.getRoot();

    root->setValue("0");

    root->addChild();
    root->addChild();
    root->addChild();
    root->getChild(0)->setValue("1");
    root->getChild(1)->setValue("2");
    root->getChild(2)->setValue("3");

    root->getChild(2)->addChild();
    root->getChild(2)->getChild(0)->setValue("4");

    root->getChild(2)->getChild(0)->addChild();
    root->getChild(2)->getChild(0)->getChild(0)->setValue("5");

    return tree;
}

TreeDynamic<double> createTree4() {

    TreeDynamic<double> tree;
    NodeDynamic<double>* root = tree.getRoot();

    root->setValue(0.1);

    root->addChild();
    root->addChild();
    root->addChild();
    root->getChild(0)->setValue(1.1);
    root->getChild(1)->setValue(2.1);
    root->getChild(2)->setValue(3.1);

    root->getChild(2)->addChild();
    root->getChild(2)->getChild(0)->setValue(4.1);

    root->getChild(2)->getChild(0)->addChild();
    root->getChild(2)->getChild(0)->getChild(0)->setValue(5.1);

    return tree;
}

int main() {

//* test
    TreeDynamic<int> tree1 = createTree1();
    TreeDynamic<int> tree2 = createTree2();
    tree1.printTree();
    tree2.printTree();

    std::cout << std::endl;

    tree1.moveSubtree(tree1.getRoot()->getChild(2), tree2.getRoot()->getChild(0));

    tree1.printTree();
    tree2.printTree();

    std::cout << std::endl;

    TreeDynamic<std::string> tree3 = createTree3();
    tree3.printTree();

    std::cout << std::endl;

    TreeDynamic<double> tree4 = createTree4();

    std::cout << "Suma wartosci w drzewie: " << tree4.sumOfValues() << std::endl << std::endl;
}
