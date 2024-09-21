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
    int n, q;
    cin >> n >> q;
    string *arr = new string[n];
    int *ans = new int[q]{0};
    string temp;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < q; i++)
    {
        cin >> temp;
        for (int j = n - 1; j >= 0; j--)
        {
            if (arr[i].length() < temp.length())
                break;
            if (temp == arr[j].substr(0, temp.length()))
                ans[i]++;
        }
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << endl;
    delete[] arr;
    delete[] ans;
}