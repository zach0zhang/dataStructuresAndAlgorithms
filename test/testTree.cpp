#include <iostream>
#include <cassert>
#include "LinkedBinaryTree.h"

using namespace std;

#define NUM 50

static void testLinkedBinaryTree()
{
    LinkedBinaryTree<int> myTree;
    LinkedBinaryTree<int>::Position p;

    assert(myTree.size() == 0);
    assert(myTree.empty() == true);

    myTree.addRoot();
    assert(myTree.root().isRoot());
    assert(myTree.size() == 1);
    assert(myTree.empty() == false);

    myTree.expendExternal(myTree.root());
    assert(myTree.size() == 3);

    myTree.removeAboveExternal(myTree.root().left());
    assert(myTree.size() == 1);

    for (int i = 1; i < NUM; i++)
        myTree.addNode(i);

    LinkedBinaryTree<int>::PositionList pList = myTree.levelOrder();
    typename LinkedBinaryTree<int>::PositionList::iterator it = pList.begin();
    
    for (int i = 0; i < NUM; i++) {
        p = *it;
        assert(*p == i);
        it++;
    }
}

void testTree()
{
    cout << "test Linked binary tree" << endl;
    testLinkedBinaryTree();
}