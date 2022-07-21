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
    int n, m;
    vector<int> arr;
    vector<int> ans;
    vector<int> casesUp;
    vector<int> casesDown;

    int s, t;

    cin >> n >> m;
    int in;

    for (int i = 0; i < n; i++)
    {
        cin >> in;
        arr.push_back(in);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> s;
        cin >> t;
        ans.push_back(0);

        if (s <= t)
        {
            for (int j = s - 1; j < t - 1; j++)
            {
                if (arr[j + 1] < arr[j])
                    ans[i] += arr[j] - arr[j + 1];
            }
        }
        else
        {
            for (int j = s - 1; j > t - 1; j--)
            {
                if (arr[j - 1] < arr[j])
                    ans[i] += arr[j] - arr[j - 1];
            }
        }
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << endl;
}
