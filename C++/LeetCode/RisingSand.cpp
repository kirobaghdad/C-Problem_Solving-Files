#include <iostream>
#include <limits.h>
using namespace std;

template <class T>
void readArray(T arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

template <class T>
void printArray(T arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int getMin(int *arr, int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int func(int *arr, int n, int k)
{
    int numOfPiles = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] > (arr[i - 1] + arr[i + 1]))
        {
            numOfPiles++;
        }
    }
    return numOfPiles;
}

int main()
{
    int t;
    cin >> t;
    int *ans = new int[t];
    int n, k;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        int *arr = new int[n];
        readArray(arr, n);
        ans[i] = func(arr, n, k);
        delete[] arr;
    }

    printArray(ans, t);
    delete[] ans;
}
