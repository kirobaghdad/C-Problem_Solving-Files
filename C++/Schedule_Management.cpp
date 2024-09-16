#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>
#include <queue>
#include <stack>
using namespace std;

int func(int *arr, int n, int m)
{
    int *tasks = new int[m]{0};
    int *min;

    for (int i = 0; i < m; i++)
    {
        min = min_element(tasks, tasks + m);
        if (*min == tasks[arr[i] - 1])
            tasks[arr[i] - 1]++;
        else if (*min < tasks[arr[i] - 1])
            min += 2;
    }
    return *max_element(tasks, tasks + m);
}

int main()
{
    int t;
    cin >> t;
    int n, m;
    int *arr;
    int *ans = new int[t];

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        arr = new int[m];
        for (int j = 0; j < m; j++)
            cin >> arr[j];
        ans[i] = func(arr, n, m);
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;
}