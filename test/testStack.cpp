#include <iostream>
#include <cassert>
#include <stack>
#include <vector>

#include "ArrayStack.h"
#include "LinkedStack.h"
#include "DequeStack.h"

using namespace std;

#define NUM  50

template <typename E>
void reverse(vector<E>& V) {
    LinkedStack<E> S;
    for (int i = 0; i < (int)V.size(); i++)
        S.push(V[i]);
    
    for (int i = 0; i < (int)V.size(); i++) {
        V[i] = S.top();
        S.pop();
    }
}

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

    // test vector reverse with stack
    vector<int> v;
    for (int i = 0; i < NUM; i++)
        v.push_back(i);
    for (int i = 0; i < NUM; i++)
        assert(v[i] == i);

    reverse(v);

    for (int i = 0; i < NUM; i++)
        assert(v[i] == NUM - 1 - i);
    
}

static void testDequeStack()
{
    DequeStack<int> myStack;
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
        assert(strTmp== "pop of empty stack");
    }

    try {
        myStack.top();
    } catch (StackEmpty& e) {
        string strTmp = e.what();
        assert(strTmp== "top from empty stack");
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

    cout << "test deque stack" << endl;
    testDequeStack();
}