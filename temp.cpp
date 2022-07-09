#include <iostream>
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

int main()
{
    int t;
    cin >> t;
    int *ans = new int[t];
    int n;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int *arr = new int[n];
        readArray(arr, n);
        ans[i] = func(arr, n);
        delete[] arr;
    }

    printArray(ans, t);
    delete[] ans;
}
