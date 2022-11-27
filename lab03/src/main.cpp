#include "NodeStatic.hpp"
#include "TreeStatic.hpp"
#include "NodeDynamic.hpp"
#include "TreeDynamic.hpp"
#include <iostream>

NodeStatic createTree1() {

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

    return root;
}

TreeStatic createTree2() {

    TreeStatic tree;
    NodeStatic* root = tree.getRoot();

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

TreeStatic createTree3() {

    TreeStatic tree;
    NodeStatic* root = tree.getRoot();

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

NodeDynamic* createTree4() {

    NodeDynamic* root = new NodeDynamic();

    root->addChild();
    root->addChild();
    root->getChild(0)->setValue(1);
    root->getChild(1)->setValue(2);

    root->getChild(0)->addChild();
    root->getChild(0)->addChild();
    root->getChild(0)->getChild(0)->setValue(11);
    root->getChild(0)->getChild(1)->setValue(12);

    root->getChild(1)->addChild();
    root->getChild(1)->addChild();
    root->getChild(1)->getChild(0)->setValue(21);
    root->getChild(1)->getChild(1)->setValue(22);

    return root;
}

TreeDynamic* createTree5() {

    TreeDynamic* tree = new TreeDynamic();
    NodeDynamic* root = tree->getRoot();

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

TreeDynamic* createTree6() {

    TreeDynamic* tree = new TreeDynamic();
    NodeDynamic* root = tree->getRoot();

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


int main() {

// test 1
/*     NodeStatic tree1 = createTree1();

    tree1.printBelow();

    std::cout << std::endl;
    std::cout << std::endl;

    tree1.getChild(0)->getChild(1)->printAbove(); */

// test 2
/*     TreeStatic tree2 = createTree2();
    TreeStatic tree3 = createTree3();

    tree2.printTree();
    tree3.printTree();

    std::cout << std::endl;

    tree2.moveSubtree(tree2.getRoot()->getChild(2), tree3.getRoot()->getChild(0));

    tree2.printTree();
    tree3.printTree(); */

// test 3
/*     NodeDynamic* tree4 = createTree4();

    tree4->printBelow();

    std::cout << std::endl;
    std::cout << std::endl;

    tree4->getChild(0)->getChild(1)->printAbove();

    delete tree4; */

// test 4
/*     TreeDynamic* tree5 = createTree5();
    TreeDynamic* tree6 = createTree6();

    tree5->printTree();
    tree6->printTree();

    std::cout << std::endl;

    tree5->moveSubtree(tree5->getRoot()->getChild(2), tree6->getRoot()->getChild(0));

    tree5->printTree();
    tree6->printTree();

    delete tree5;
    delete tree6; */

// test 5
    NodeStatic tree1 = createTree1();

    NodeStatic* child1 = tree1.getChild(0);
    NodeStatic* child2 = child1->getChild(0);
    NodeStatic* child3 = tree1.getChild(1);

    if (child1->isRelatedTo(*child2))
        std::cout << "related" << std::endl;

    if (!child3->isRelatedTo(*child1))
        std::cout << "unrelated" << std::endl;
}
