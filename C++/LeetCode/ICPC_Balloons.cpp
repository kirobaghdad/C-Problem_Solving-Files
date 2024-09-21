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

// naming var in ps
int main()
{
    int t;
    cin >> t;
    int n;
    char *arr;
    int *ans = new int[t];
    char in;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arr = new char[n]{'\0'};
        ans[i] = n * 2;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
            if (j)
                if (find(arr, arr + j, arr[j]) != arr + j)
                {
                    ans[i]--;
                }
        }
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;

    system("pause");
}