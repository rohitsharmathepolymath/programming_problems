#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMissingNumber(vector<int> &arr)
{

    int n = arr.size();
    unordered_map<int, int> map;
    for (int i = 1; i <= n; i++)
    {
        map[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        map[arr[i]] = 1;
    }
    for (auto el : map)
    {
        if (el.second == 0)
        {
            return el.first;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {1, 8, 5, 4, 7, 6, 5, 3};

    int mvalue = findMissingNumber(a);

    cout << "Missing Number is:" << mvalue;

    return 0;
}