#include <iostream>

using namespace std;

union point
{
    int x;
    float y;
};

int main()
{
    point p;
    p.x = 10;
    cout << "x: " << p.x << endl;

    p.y = 20.5;
    cout << "y: " << p.y << endl;

    cout << "x: " << p.x << endl; // This will give an undefined value since x and y share the same memory location

    return 0;
}