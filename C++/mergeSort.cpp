#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> l1(n1), l2(n2);

    for (int i = 0; i < n1; i++)
    {
        l1[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        l2[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (l1[i] <= l2[j])
        {
            arr[k] = l1[i];
            i++;
        }
        else
        {
            arr[k] = l2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = l1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = l2[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main()
{
    vector<int> arr = {12, 43, 34, 234, 5, 43, 134, 65, 2643, 145, 645};

    mergeSort(arr, 0, arr.size() - 1);

    for (const int a : arr)
    {
        cout << a << " ";
    }

    return 0;
}