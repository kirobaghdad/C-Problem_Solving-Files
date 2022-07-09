#include <iostream>
#include <limits.h>
using namespace std;

int combinationUtil(int arr[], int data[],
                    int start, int end,
                    int index, int r);

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
bool exist(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return true;
    }
    return false;
}
int sum(int *arr, int b, int f)
{
    int sum = 0;
    for (int i = b; i <= f; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int xoring(int *arr, int l, int r)
{
    int x = 0;
    for (int i = l + 1; i <= r; i++)
    {
        if (i == (l + 1))
            x += (arr[i] ^ arr[i - 1]);
        else
        {
            x = x ^ arr[i];
        }
    }
    return x;
}

int printCombination(int arr[], int n, int r)
{
    // A temporary array to store
    // all combination one by one
    int *data = new int[r];

    // Print all combination using
    // temporary array 'data[]'
    return combinationUtil(arr, data, 0, n - 1, 0, r);
}

/* arr[] ---> Input Array
data[] ---> Temporary array to
store current combination
start & end ---> Starting and
Ending indexes in arr[]
index ---> Current index in data[]
r ---> Size of a combination to be printed */
int combinationUtil(int arr[], int data[],
                    int start, int end,
                    int index, int r)
{
    bool x;
    // Current combination is ready
    // to be printed, print it
    if (index == r)
    {
        if (exist(data, r, xoring(data, 0, r)))
            return xoring(data, 0, r);
    }

    // replace index with all possible
    // elements. The condition "end-i+1 >= r-index"
    // makes sure that including one element
    // at index will make a combination with
    // remaining elements at remaining positions
    for (int i = start; i <= end &&
                        end - i + 1 >= r - index;
         i++)
    {
        data[index] = arr[i];
        return combinationUtil(arr, data, i + 1, end, index + 1, r);
    }
    return false;
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
        ans[i] = printCombination(arr, n, n - 1);
        delete[] arr;
    }

    printArray(ans, t);
    delete[] ans;
}
