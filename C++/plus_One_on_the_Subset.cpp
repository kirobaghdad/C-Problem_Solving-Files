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

int main()
{
    int t, n;
    cin >> t;
    int *ans = new int[t];
    int *arr;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arr = new int[n];
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        ans[i] = *max_element(arr, arr + n) - *min_element(arr, arr + n);
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;
}