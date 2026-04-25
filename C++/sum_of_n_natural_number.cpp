#include <iostream>
#include <chrono>

using namespace std;

#define ull long long

int main()
{
    ull n;
    cout << "Enter a Number: ";
    cin >> n;

    auto start = chrono::high_resolution_clock::now();

    ull sum = (n * (n + 1)) / 2;

    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();

    cout << "Sum of " << n << " natural numbers is: " << sum << endl;
    cout << "Execution time is: " << duration << " Microseconds" << endl;

    return 0;
}
