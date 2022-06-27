#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
void merge(int *&arr, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int i, j;

    int *left = new int[n1 + 1];
    int *right = new int[n2 + 1];

    for (i = 0; i < n1; i++)
        left[i] = arr[p + i];

    for (j = 0; j < n2; j++)
        right[j] = arr[q + j + 1];

    left[n1] = INT_MIN;
    right[n2] = INT_MIN;

    i = 0, j = 0;
    for (int k = p; k <= r; k++)
    {
        if (left[i] < right[j])
        {
            arr[k] = right[j];
            j++;
        }
        else
        {
            arr[k] = left[i];
            i++;
        }
    }

    delete[] left;
    delete[] right;
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
void mergeSort(int *&arr, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void getSum(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i)
            arr[i] = arr[i] + arr[i - 1];
    }
}

int promo(int *arr, int n, int x, int y)
{
    if (x == y)
        return arr[x - 1];
    return arr[x - 1] - arr[x - y - 1];
}

int main()
{
    int q;
    int n;
    cin >> n;
    cin >> q;
    int x, y;
    int *ans = new int[q];
    int *arr = new int[n];
    readArray(arr, n);
    mergeSort(arr, 0, n - 1);
    getSum(arr, n);

    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        ans[i] = promo(arr, n, x, y);
    }

    printArray(ans, q);
    delete[] ans;
    delete[] arr;
}

/*

#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
void merge(int*& arr, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int i, j;

    int* left = new int[n1 + 1];
    int* right = new int[n2 + 1];

    for (i = 0; i < n1; i++)
        left[i] = arr[p + i];

    for (j = 0; j < n2; j++)
        right[j] = arr[q + j + 1];

    left[n1] =  INT_MAX;
    right[n2] = INT_MAX;

    i = 0, j = 0;
    for (int k = p; k <= r; k++)
    {
        if (left[i] > right[j])
        {
            arr[k] = right[j];
            j++;
        }
        else
        {
            arr[k] = left[i];
            i++;
        }
    }

    delete[] left;
    delete[] right;
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
void mergeSort(int*& arr, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void getSum(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i)
            arr[i] = arr[i] + arr[i - 1];
    }
}

int promo(int* arr, int n, int x, int y)
{
    if (n == x)
        return arr[n - x + y - 1];
    return arr[n - x + y - 1] - arr[n - x - 1];
}

int main()
{
    int q;
    int n;
    cin >> n;
    cin >> q;
    int x, y;
    int* ans = new int[q];
    int* arr = new int[n];
    readArray(arr, n);
    mergeSort(arr, 0, n - 1);
    getSum(arr, n);

     for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        ans[i] = promo(arr, n, x, y);
    }

    printArray(ans, q);
    delete[] ans;
    delete[] arr;
}


*/