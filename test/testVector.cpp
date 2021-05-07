#include <iostream>
#include <vector>
#include <cassert>

#include "ArrayVector.h"

using namespace std;

#define NUM 50

static void testVectorWithSTL()
{
    vector<int> myVector;

    assert(myVector.size() == 0);
    assert(myVector.empty() == true);

    for (int i = 0; i < NUM; i++) {
        myVector.push_back(i);
        assert(myVector.back() == i);
    }

    assert(myVector.size() == NUM);
    assert(myVector.empty() == false);

    for (int i = NUM - 1; i >= 0; i--) {
        assert(myVector[i] == i);
        myVector.pop_back();
    }

    assert(myVector.empty() == true);
}


static void testArrayVector()
{
    ArrayVector<int> myVector;

    assert(myVector.size() == 0);
    assert(myVector.empty() == true);

    for (int i = 0; i < NUM; i++) {
        myVector.push_back(i);
        assert(myVector.at(i) == i);
    }

    assert(myVector.size() == NUM);
    assert(myVector.empty() == false);

    for (int i = NUM - 1; i >= 0; i--) {
        assert(myVector[i] == i);
        assert(myVector.size() == i + 1);
        myVector.pop_back();
    }

    assert(myVector.empty() == true);

}

static void testVectorIterator()
{
    vector<int> myVector;
    int sum = 0;
    typedef vector<int>::iterator Iterator;

    for (int i = 0; i < NUM; i++) {
        myVector.push_back(i);
        sum += i;
    }
    
    for (Iterator p = myVector.begin(); p != myVector.end(); ++p)
        sum -= *p;

    assert(sum == 0);
}   

void testVector()
{
    cout << "test vector with stl" << endl;
    testVectorWithSTL();

    cout << "test array vector" <<endl;
    testArrayVector();

    cout << "test vector iterator" << endl;
    testVectorIterator();
}