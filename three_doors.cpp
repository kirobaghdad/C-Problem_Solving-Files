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

bool func(int *arr, int x, int i = 0)
{

    if (i == 2)
    {
        return true;
    }
    else
    {
        if (!arr[x])
        {
            return 0;
        }
    }

    return func(arr, arr[x] - 1, i + 1);
}

int main()
{
    int t;
    cin >> t;
    int x, a, b, c;
    bool *ans = new bool[t];
    int arr[3];

    for (int i = 0; i < t; i++)
    {
        cin >> x >> arr[0] >> arr[1] >> arr[2];
        ans[i] = func(arr, x - 1);
    }

    for (int i = 0; i < t; i++)
        ans[i] ? cout << "YES" << endl : cout << "NO" << endl;
}

/*
for (int i = 0; i < t; i++)
    {
        cin >> x;
        cin >> arr[0] >> arr[1] >> arr[2];

        for (int j = 0; j < 3; j++)
        {
            if (!j)
            {
                if (!arr[x - 1])
                {
                    ans[i] = 0;
                    break;
                }
            }
            else
            {

            }
        }
    }
*/