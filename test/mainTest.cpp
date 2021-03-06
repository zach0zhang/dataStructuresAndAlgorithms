#include <iostream>

using namespace std;

extern void testList();
extern void testStack();
extern void testQueue();
extern void testVector();
extern void testTree();
extern void testMap();

int main(int argc, char *argv[])
{
    cout << "Performing test for list" << endl;
    testList();

    cout << "Performing test for stack" << endl;
    testStack();

    cout << "Performing test for queue" << endl;
    testQueue();

    cout << "Performing test for vector" << endl;
    testVector();

    cout << "Performing test for tree" << endl;
    testTree();

    cout << "Performing test for map" << endl;
    testMap();

    return 0;
}