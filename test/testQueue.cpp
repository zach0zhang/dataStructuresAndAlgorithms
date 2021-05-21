#include <iostream>
#include <queue>
#include <cassert>
#include <string>

#include "LinkedQueue.h"
#include "LinkedDeque.h"
#include "NodeSequence.h"
#include "ListPriorityQueue.h"
#include "HeapPriorityQueue.h"
#include "AdaptPriorityQueue.h"

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

struct tmpLittle {
    bool operator() (int a, int b) {
        return a > b;
    }
};

static void testPriorityQueueWithSTL()
{
    priority_queue<int> myQueue;

    assert(myQueue.size() == 0);
    assert(myQueue.empty() == true);

    for (int i = 0; i < NUM; i++)
        myQueue.push(i);

    for (int i = NUM - 1; i >= 0; i--) {
        assert(myQueue.top() == i);
        myQueue.pop();
    }

    priority_queue<int, vector<int>, tmpLittle> littleQueue;

    for (int i = 0; i < NUM; i++)
        littleQueue.push(i);

    for (int i = 0; i < NUM; i++) {
        assert(littleQueue.top() == i);
        littleQueue.pop();
    }
}

struct intLess {
    bool operator() (const int a, const int b) {
        return a < b;
    }
};

static void testListPriorityQueue()
{
    ListPriorityQueue<int, intLess> myQueue;

    assert(myQueue.empty() == true);
    assert(myQueue.size() == 0);


    for (int i = 0; i < 10; i++)
        myQueue.insert(i);
    for (int i = 20; i >= 10; i--)
        myQueue.insert(i);
    for (int i = 21; i < NUM; i++)
        myQueue.insert(i);

    for (int i = 0; i < NUM; i++) {
        assert(myQueue.min() == i);
        myQueue.removeMin();
    }
}

static void testHeapPriorityQueue()
{
    HeapPriorityQueue<int, intLess> myQueue;

    assert(myQueue.empty() == true);
    assert(myQueue.size() == 0);

    for (int i = 0; i < 10; i++)
        myQueue.insert(i);
    for (int i = 20; i >= 10; i--)
        myQueue.insert(i);
    for (int i = 21; i < NUM; i++)
        myQueue.insert(i);
    

    for (int i = 0; i < NUM; i++) {
        assert(myQueue.min() == i);
        myQueue.removeMin();
    }
}

static void testAdaptPriorityQueue()
{
    AdaptPriorityQueue<int, intLess> myQueue;
    typedef AdaptPriorityQueue<int, intLess>::Position Position;
    Position pos, pos20;

    assert(myQueue.empty() == true);
    assert(myQueue.size() == 0);

    for (int i = 0; i < 10; i++) {
        pos = myQueue.insert(i);
        assert(*pos == i);
    }

    pos20 = myQueue.insert(20);
    assert(*pos20 == 20);

    for (int i = 19; i >= 10; i--) {
        pos = myQueue.insert(i);
        assert(*pos == i);
    }
    for (int i = 21; i < NUM; i++) {
        pos = myQueue.insert(i);
        assert(*pos == i);
    }

    pos = myQueue.replace(pos20, 30);
    assert(*pos == 30);
    myQueue.remove(pos);
    myQueue.insert(20);
    

    for (int i = 0; i < NUM; i++) {
        assert(myQueue.min() == i);
        myQueue.removeMin();
    }

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

    cout << "test priority queue with STL" << endl;
    testPriorityQueueWithSTL();

    cout << "test list priority queue" << endl;
    testListPriorityQueue();

    cout << "test heap priority queue" << endl;
    testHeapPriorityQueue();

    cout << "test adapt priority queue" << endl;
    testAdaptPriorityQueue();
}