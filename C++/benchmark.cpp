#include <iostream>
#include <chrono>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

int main()
{
    // 17-digit numbers
    unsigned long long ull_a = 12345678901234567ULL;
    unsigned long long ull_b = 98765432101234567ULL;

    cpp_int big_a = ull_a;
    cpp_int big_b = ull_b;

    const int ITER = 1000000; // 1 million multiplications

    // Benchmark ULL
    auto start_ull = chrono::high_resolution_clock::now();
    unsigned long long ull_res = 0;
    for (int i = 0; i < ITER; ++i)
    {
        ull_res = ull_a * ull_b;
    }
    auto end_ull = chrono::high_resolution_clock::now();
    auto dur_ull = chrono::duration_cast<chrono::microseconds>(end_ull - start_ull).count();

    // Benchmark cpp_int
    auto start_big = chrono::high_resolution_clock::now();
    cpp_int big_res;
    for (int i = 0; i < ITER; ++i)
    {
        big_res = big_a * big_b;
    }
    auto end_big = chrono::high_resolution_clock::now();
    auto dur_big = chrono::duration_cast<chrono::microseconds>(end_big - start_big).count();

    cout << "ULL multiplication time: " << dur_ull << " microseconds\n";
    cout << "cpp_int multiplication time: " << dur_big << " microseconds\n";
}
