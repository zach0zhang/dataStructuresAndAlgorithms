#include <iostream>
#include <cassert>
#include "LinkedBinaryTree.h"
#include "VectorCompleteTree.h"
#include "SearchTree.h"

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

static void testSearchTree()
{
    Entry<int, string> pair;
    SearchTree<Entry<int, string>> myTree;
    SearchTree<Entry<int, string>>::Iterator p = myTree.begin();

    int keyList[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    string valueList[10] = {"zero", "one", "two", "three", "four"\
                        "five", "six", "seven", "eight", "nine"};

    assert(myTree.empty() == true);
    assert(myTree.size() == 0);

    for (int i = 0; i < 10; i++) {
        p = myTree.insert(keyList[i], valueList[i]);
        pair = *p;
        assert(pair.key() == keyList[i]);
        assert(pair.value() == valueList[i]);
    }

    assert(myTree.empty() == false);
    assert(myTree.size() == 10);

    for (int i = 0; i < 10; i++) {
        p = myTree.find(keyList[i]);
        assert((*p).value() == valueList[i]);
    }
    p = myTree.find(10);
    assert(myTree.end() == p);

    myTree.erase(9);
    assert(myTree.size() == 9);
    p = myTree.find(8);
    myTree.erase(p);

    try {
        myTree.erase(8);
    } catch(NonexistentElement& e) {
        string strTmp = e.what();
        assert(strTmp == "Erase of nonexistent");
    }


    myTree.insert(keyList[8], valueList[8]);
    myTree.insert(keyList[9], valueList[9]);
    p = myTree.begin();
    while (!(p==myTree.end())) {
        myTree.erase(p);
        ++p;
    }

    assert(myTree.empty() == true);
    assert(myTree.size() == 0);
}

void testTree()
{
    cout << "test Linked binary tree" << endl;
    testLinkedBinaryTree();

    cout << "test vector complete tree" << endl;
    testVectorCompleteTree();

    cout << "test search tree" << endl;
    testSearchTree();
}