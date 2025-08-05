#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <chrono>
using namespace std;
using namespace boost::multiprecision;

// Fast doubling method
pair<cpp_int, cpp_int> fib_pair(unsigned long long n)
{
    if (n == 0)
        return {0, 1};
    auto p = fib_pair(n >> 1);
    cpp_int a = p.first;  // F(k)
    cpp_int b = p.second; // F(k+1)

    cpp_int c = a * ((b << 1) - a); // F(2k) = F(k) * [2*F(k+1) − F(k)]
    cpp_int d = a * a + b * b;      // F(2k+1) = F(k)^2 + F(k+1)^2

    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

int main()
{
    unsigned long long n;
    cout << "Enter n for nth Fibonacci number: ";
    cin >> n;

    auto start = chrono::high_resolution_clock::now();
    cpp_int Fn = fib_pair(n).first; // F(n)
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Execution time: " << duration << " ms\n";
    cout << "Fibonacci(" << n << ") has " << Fn.str().size() << " digits\n";
    // Uncomment below line to print full number (be careful for very large n!)
    // cout << Fn << endl;
}
