#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber(vector<int> &arr)
{

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int val = abs(arr[i]);
        arr[val - 1] = -arr[val - 1];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {1, 4, 5, 4, 7, 6, 2, 3};

    int mvalue = findMissingNumber(a);

    cout << "Missing Number is:" << mvalue;

    return 0;
}