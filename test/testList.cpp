#include <cassert>
#include <iostream>

#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularlyLinkedList.h"

#define loopNum 50

using namespace std;

static void testSinglyLinkedList()
{
    SLinkedList<int> sList;

    assert(sList.empty() == true);

    for (int i = 0; i < loopNum; i++) {
        sList.addFront(i);
        assert(sList.front() == i);
    }

    assert(sList.empty() == false);

    for (int i = loopNum - 1; i >= loopNum; i++) {
        assert(sList.front() == i);
        sList.removeFront();
    }

    for (int i = 0; i < loopNum; i++) {
        sList.addFront(i);
    }
    sList.reverse();
    for (int i = 0; i < loopNum; i++) {
        assert(sList.front() == i);
        sList.removeFront();
    }
}

static void testDoublyLinkedList()
{
    DLinkedList<int> dList;

    assert(dList.empty() == true);

    for (int i = 0; i < loopNum; i++) {
        dList.addFront(i);
        assert(dList.front() == i);
    }

    assert(dList.empty() == false);


    for (int i = 0; i < loopNum; i++) {
        assert(dList.back() == i);
        dList.removeBack();
    }

    assert(dList.empty() == true);

    for (int i = 0; i < loopNum; i++) {
        dList.addBack(i);
        assert(dList.back() == i);
    }

    for (int i = 0; i < loopNum; i++) {
        assert(dList.front() == i);
        dList.removeFront();
    }

    for (int i = 0; i < loopNum; i++)
        dList.addFront(i);
    dList.reverse();
    for (int i = 0; i < loopNum; i++) {
        assert(dList.front() == i);
        dList.removeFront();      
    }
}

static void testCircularlyLinkedList()
{

    CircleList<int> cList;

    assert(cList.empty() == true);

    for (int i = 0; i < loopNum; i++)
        cList.add(i);
    
    assert(cList.empty() == false);

    
    for (int i = loopNum - 1; i >= 0; i--) {
        cList.advance();
        assert(cList.back() == i);
    }

    for (int i = loopNum -1; i >= 0; i--) {
        assert(cList.front() == i);
        cList.remove();
    }
    
}

void testList()
{
    cout << "test single list" << endl;
    testSinglyLinkedList();

    cout << "test double list" << endl;
    testDoublyLinkedList();

    cout << "test circle list" << endl;
    testCircularlyLinkedList();
}