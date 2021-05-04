#include <iostream>
#include <cassert>
#include <stack>

#include "ArrayStack.h"
#include "LinkedStack.h"

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
    ArrayStack<int> myStack;
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

static void testLinkedStack()
{
    LinkedStack<int> myStack;
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

    try {
        myStack.pop();
    } catch (StackEmpty& e) {
        string strTmp = e.what();
        assert(strTmp== "Pop from empty stack");
    }

    try {
        myStack.top();
    } catch (StackEmpty& e) {
        string strTmp = e.what();
        assert(strTmp== "Top of empty stack");
    }
}

void testStack()
{
    cout << "test stack with stl" << endl;
    testStackWithSTL();

    cout << "test array stack" << endl;
    testArrayStack();

    cout << "test linked stack" << endl;
    testLinkedStack();
}