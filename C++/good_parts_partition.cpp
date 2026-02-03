#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>

using namespace std;

const int MOD = 1e9 + 7;

int CountWays(int N, int K, vector<int>& A) {
    vector<int> dp(N + 1, 0); // dp[i] stores the number of ways to partition the first i elements
    dp[0] = 1; // Base case: one way to partition an empty array

    for (int i = 1; i <= N; ++i) {
        int min_elem = INT_MAX;
        int max_elem = INT_MIN;
        
        for (int j = i; j > 0; --j) { // Look back to partition
            min_elem = min(min_elem, A[j - 1]);
            max_elem = max(max_elem, A[j - 1]);

            if (max_elem - min_elem > K) {
                break; // If the difference exceeds K, stop checking further
            }

            dp[i] = (dp[i] + dp[j - 1]) % MOD;
        }
    }

    return dp[N];
}

int main() {
    int N, K;
    cout << "Enter the length of the array (N): ";
    cin >> N;

    cout << "Enter the value of K: ";
    cin >> K;

    vector<int> A(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int result = CountWays(N, K, A);
    cout << "Total number of ways to partition the array into good parts: " << result << endl;

    return 0;
}
