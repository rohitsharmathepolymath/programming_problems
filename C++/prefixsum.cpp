#include <iostream>
#include <vector>

using namespace std;
vector<int> prefixsum(vector<int> arr)
{
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    return prefix;
}

int main()
{

    int n;

    cout << "Enter the size of the vector: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the element in the vector:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl;
    cout << "The Value Entered by you.";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i == n - 1)
        {
            continue;
        }
        cout << ", ";
    }
    cout << endl;
    vector<int> prefix(arr.size());
    prefix = prefixsum(arr);

    cout << "Prefix sum:";
    for (int i = 0; i < n; i++)
    {
        cout << prefix[i];
        if (i == n - 1)
        {
            continue;
        }
        cout << ", ";
    }
    return 1;
}