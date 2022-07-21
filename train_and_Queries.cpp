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
    int t;
    cin >> t;
    vector<vector<bool>> ans;

    int n, k;
    int *arr;
    int a, b;
    int *kArr = new int[t];
    bool aFound = 0;
    bool bFound = 0;
    for (int i = 0; i < t; i++)
    {

        cin >> n >> k;
        arr = new int[n];
        kArr[i] = k;
        ans.push_back(vector<bool>(k, 0));

        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }

        // for (int l = 0; l < k; l++)
        // {
        //     cin >> a >> b;
        //     aFound = 0;
        //     bFound = 0;
        //     for (int m = 0; m < n; m++)
        //     {

        //         if (arr[m] == a && !aFound)
        //             aFound = true;

        //         if (aFound)
        //         {
        //             if (arr[m] == b)
        //             {
        //                 bFound = true;
        //                 break;
        //             }
        //         }
        //     }
        //     ans[i][l] = (aFound & bFound);
    }
    delete[] arr;
}

for (int i = 0; i < t; i++)
{
    for (int j = 0; j < kArr[i]; j++)
    {
        ans[i][j] ? cout << "YES" : cout << "NO";
        cout << endl;
    }
}

delete[] kArr;

system("pause");
return 0;
}