#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <chrono>
using namespace std;
using namespace boost::multiprecision;

int main()
{
    unsigned long long n;
    cout << "Enter n: ";
    cin >> n;

    cpp_int a = 0, b = 1, c;

    auto start = chrono::high_resolution_clock::now();
    cout << a << endl;
    if (n > 0)
        cout << b << endl;

    for (unsigned long long i = 2; i <= n; i++)
    {
        c = a + b;
        cout << c << endl;
        a = b;
        b = c;
    }
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Fibonacci(" << n << ") has " << c.str().size() << " digits\n";
    cout << "Execution time: " << duration << " ms\n";
}
