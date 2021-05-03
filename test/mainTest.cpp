#include <iostream>

using namespace std;

extern void testList();
extern void testStack();

int main(int argc, char *argv[])
{
    cout << "Performing test for list" << endl;
    testList();

    cout << "Performing test for stack" << endl;
    testStack();
    return 0;
}