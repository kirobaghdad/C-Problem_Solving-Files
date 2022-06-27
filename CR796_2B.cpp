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

int countOdds(int *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 1)
            count++;
    }
    return count;
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

int *getZeros(int *arr, int n)
{
    int *zeros = new int[n]{};
    int x;
    for (int i = 0; i < n; i++)
    {
        x = arr[i] & ~(arr[i] - 1);
        while (x / 2)
        {
            zeros[i]++;
            x /= 2;
        }
        x = 0;
    }
    return zeros;
}

int func(int *arr, int n)
{
    int odds = countOdds(arr, n);
    if (odds)
    {
        return n - odds;
    }
    else
    {
        int *numOfZeros;
        numOfZeros = getZeros(arr, n);
        return getMin(numOfZeros, n) + n - 1;
    }
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
