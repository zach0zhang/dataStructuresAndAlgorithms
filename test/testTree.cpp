#include <iostream>
#include <cassert>
#include "LinkedBinaryTree.h"
#include "VectorCompleteTree.h"

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

static void testVectorCompleteTree()
{
    VectorCompleteTree<int> myTree;
    VectorCompleteTree<int>::Position p;

    assert(myTree.size() == 0);

    for (int i = 0; i < NUM; i++) {
        myTree.addList(i);
        assert(*myTree.last() == i);
    }

    p = myTree.root();
    assert(myTree.isRoot(p) == true);

    for (int i = 0; i < 10; i++) {
        p++;
        assert(myTree.hasLeft(p) == true);
        assert(myTree.hasRight(p) == true);
        assert(*myTree.left(p) == 2 * (i+2) - 1);
        assert(*myTree.right(p) == 2 * (i+2));

    }

    p = myTree.root() + NUM - 1;
    assert(myTree.hasLeft(p) == false);
    assert(myTree.hasRight(p) == false);


    assert(*myTree.root() == 0);
    myTree.swap(myTree.root(), (myTree.root() + NUM - 1));
    assert(*myTree.root() == 49);
    
    for ( int i = 0; i < NUM; i++)
        myTree.removeLast();

    assert(myTree.size() == 0);


}

void testTree()
{
    cout << "test Linked binary tree" << endl;
    testLinkedBinaryTree();

    cout << "test vector complete tree" << endl;
    testVectorCompleteTree();
}