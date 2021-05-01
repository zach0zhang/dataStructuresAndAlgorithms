#include <iostream>

using namespace std;

extern void testList();

int main(int argc, char *argv[])
{
    cout << "Performing test for list" <<endl;
    testList();
    return 0;
}