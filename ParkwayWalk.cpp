#include <iostream>
using namespace std;

int parkwayWalk(int *arr, int n, int m)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum >= m)
        return sum - m;
    else
    {
        return 0;
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

template <class T>
void readArray(T arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    int t;
    cin >> t;
    int *ans = new int[t];
    int *arr;
    int m, n;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        arr = new int[n];
        readArray(arr, n);
        ans[i] = parkwayWalk(arr, n, m);
        delete[] arr;
    }

    printArray(ans, t);
    delete[] ans;
}