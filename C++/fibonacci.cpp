#include <iostream>

using namespace std;

int main()
{
    int a, b, c, n;
    a = 0;
    b = 1;
    cout << "Enter the number of elements in the fibnacci series: ";
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}