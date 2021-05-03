#include <iostream>
#include <cassert>
#include <stack>

#include "arrayStack.h"

using namespace std;

#define NUM  50

static void testStackWithSTL()
{
    stack<int> myStack;
    int tmp;

    assert(myStack.empty() == true);
    assert(myStack.size() == 0);

    for (int i = 0; i < NUM; i++) {
        myStack.push(i);
        assert(myStack.top() == i);
    }

    assert(myStack.empty() == false);
    assert(myStack.size() == NUM);

    for (int i = NUM - 1; i >= 0; i--) {
        tmp = myStack.top();
        myStack.pop();
        assert(tmp == i);
    }


    assert(myStack.empty() == true);
    assert(myStack.size() == 0);

}

void testArrayStack()
{
    arrayStack<int> myStack;
    int tmp;

    assert(myStack.empty() == true);
    assert(myStack.size() == 0);

    for (int i = 0; i < NUM; i++) {
        myStack.push(i);
        assert(myStack.top() == i);
    }

    assert(myStack.empty() == false);
    assert(myStack.size() == NUM);

    for (int i = NUM - 1; i >= 0; i--) {
        tmp = myStack.top();
        myStack.pop();
        assert(tmp == i);
    }


    assert(myStack.empty() == true);
    assert(myStack.size() == 0);   
}

void testStack()
{
    cout << "test stack with stl" << endl;
    testStackWithSTL();

    cout << "test array stack" << endl;
    testArrayStack();
}