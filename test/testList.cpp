#include <cassert>
#include <iostream>

#include "CircularlyLinkedList.h"

#define loopNum 50

using namespace std;

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
    cout << "test circle list" << endl;
    testCircularlyLinkedList();
}