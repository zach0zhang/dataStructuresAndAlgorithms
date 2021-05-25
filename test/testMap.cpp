#include <iostream>
#include <string>
#include <cassert>
#include "HashMap.h"

using namespace std;

struct hashCode {
    int operator() (const string str) {
        unsigned int h = 0;
        for (int i = 0; i < (int)str.length(); i++) {
            h = (h << 5) | (h >> 27);
            h += (unsigned int)str[i];
        }
        return (int)h;
    }
};

static void testHashMap()
{
    int valueList[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    string keyList[10] = {"zero", "one", "two", "three", "four",
                        "five", "six", "seven", "eight", "nine"};
    HashMap<string, int, hashCode> myMap;

    assert(myMap.size() == 0);
    assert(myMap.empty() == true);

    for (int i = 0; i < 10; i++)
        myMap.put(keyList[i], valueList[i]);


    assert(myMap.size() == 10);
    assert(myMap.empty() == false);

    HashMap<string, int, hashCode>::Iterator p = myMap.begin();
    for (p = myMap.begin(); !(p == myMap.end()); ++p) {
        //cout << (*p).key() << " "<< (*p).value() << endl;
        assert(valueList[(*p).value()] == (*p).value());
    }

    for (int i = 0; i < 10; i++) {
        p = myMap.find(keyList[i]);
        assert((*p).value() == valueList[i]);
        myMap.erase(p);
    }

    assert(myMap.size() == 0);
    assert(myMap.empty() == true);

    for (int i = 0; i < 10; i++)
        myMap.put(keyList[i], valueList[i]);

    for (int i = 0; i < 10; i++)
        myMap.erase(keyList[i]);
    
    assert(myMap.size() == 0);
    assert(myMap.empty() == true);

}

void testMap()
{
    cout << "test hash map" << endl;
    testHashMap();
}