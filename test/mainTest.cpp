#include <iostream>

using namespace std;

extern void testList();
extern void testStack();
extern void testQueue();

int main(int argc, char *argv[])
{
    cout << "Performing test for list" << endl;
    testList();

    cout << "Performing test for stack" << endl;
    testStack();

    cout << "Performing test for queue" << endl;
    testQueue();

    return 0;
}