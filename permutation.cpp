#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

int func(int n, int *arr)
{
    int i;
    int p = 0;
    for (i = 0; i <= ceil(log2(n)); i++)
        arr[i] = 2 ^ i;

    for (int j = 1; j < n; j++)
    {
        if (modf(i, &p) != 0)
            arr[i++] = i;
    }
    return n;
}

int main()
{
    int t;
    cin >> t;
    int n;
    int **perm = new int *[t];
    int *ans = new int[t];

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        perm[i] = new int[n];
        ans[i] = func(n, perm[i]);
    }

    for (int i = 0; i < t; i++)
    {
        cout << 2;
        for (int j = 0; j < ans[i]; j++)
        {
            cout << perm[i][j] << " ";
        }
        cout << endl;
    }
}