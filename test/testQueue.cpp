#include <iostream>
#include <queue>
#include <cassert>
#include <string>

#include "LinkedQueue.h"
#include "LinkedDeque.h"
#include "NodeSequence.h"

using namespace std;

#define NUM 50

static void testQueueWithSTL()
{
    queue<int> myQueue;

    assert(myQueue.size() == 0);
    assert(myQueue.empty() == true);

    for (int i = 0; i < NUM; i++) {
        myQueue.push(i);
        assert(myQueue.back() == i);
    }

    assert(myQueue.size() == NUM);
    assert(myQueue.empty() == false);

    for (int i = 0; i < NUM; i++) {
        assert(myQueue.front() == i);
        myQueue.pop();
    }

    assert(myQueue.empty() == true);
}

static void testLinkedQueue()
{
    LinkedQueue<int> myQueue;

    assert(myQueue.size() == 0);
    assert(myQueue.empty() == true);

    for (int i = 0; i < NUM; i++) {
        myQueue.enqueue(i);
    }

    assert(myQueue.size() == NUM);
    assert(myQueue.empty() == false);

    for (int i = 0; i < NUM; i++) {
        assert(myQueue.front() == i);
        myQueue.dequeue();
    }

    assert(myQueue.empty() == true);

    try {
        myQueue.front();
    } catch(QueueEmpty& e) {
        string strTmp = e.what();
        assert(strTmp == "front from empty queue");
    }

    try {
        myQueue.dequeue();
    } catch(QueueEmpty& e) {
        string strTmp = e.what();
        assert(strTmp == "dequeue of empty queue");
    }
}

static void testLinkedDeque()
{
    LinkedDeque<int> myQueue;

    assert(myQueue.size() == 0);
    assert(myQueue.empty() == true);

    for (int i = 0; i < NUM; i++) {
        myQueue.insertFront(i);
        assert(myQueue.front() == i);
    }

    assert(myQueue.size() == NUM);
    assert(myQueue.empty() == false);

    for (int i = 0; i < NUM; i++) {
        assert(myQueue.back() == i);
        myQueue.removeBack();
    }

    assert(myQueue.empty() == true);   

    for (int i = 0; i < NUM; i++) {
        myQueue.insertBack(i);
        assert(myQueue.back() == i);
    }

    for (int i = 0; i < NUM; i++) {
        assert(myQueue.front() == i);
        myQueue.removeFront();
    }

    try {
        myQueue.front();
    } catch(DequeEmpty& e) {
        string strTmp = e.what();
        assert(strTmp == "front from empty deque");
    }

    try {
        myQueue.back();
    } catch(DequeEmpty& e) {
        string strTmp = e.what();
        assert(strTmp == "back from empty deque");
    }

    try {
        myQueue.removeFront();
    } catch(DequeEmpty& e) {
        string strTmp = e.what();
        assert(strTmp == "removeFront of empty deque");
    }

    try {
        myQueue.removeBack();
    } catch(DequeEmpty& e) {
        string strTmp = e.what();
        assert(strTmp == "removeBack of empty deque");
    }
}

static void testNodeQuence()
{
    NodeSequence<int> mySequence;

    assert(mySequence.size() == 0);
    assert(mySequence.empty() == true);

    for (int i = 0; i < NUM; i++)
        mySequence.insertBack(i);

    for (int i = 0; i < NUM; i++)
        assert(*mySequence.atIndex(i) == i);

    for (int i = 0; i < NUM; i++)
        mySequence.eraseFront();

    assert(mySequence.size() == 0);
    assert(mySequence.empty() == true);

    for (int i = 0; i < NUM; i++)
        mySequence.insertFront(i);


    mySequence.intBubbleSort1();
    for (int i = 0; i < NUM; i++)
        assert(*mySequence.atIndex(i) == i);

}

void testQueue()
{
    cout << "test queue with stl" << endl;
    testQueueWithSTL();

    cout << "test linked queue" << endl;
    testLinkedQueue();

    cout << "test linked deque" << endl;
    testLinkedDeque();

    cout << "test sequence" << endl;
    testNodeQuence();
}