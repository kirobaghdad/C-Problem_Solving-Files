#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    int n;

    vector<int> nums;

    vector<int> ans(t);
    int s = 0;

    for (int i = 0; i < t; i++)
    {
        s = 0;
        cin >> n;

        nums.resize(n);

        for (int j = 0; j < n; j++)
        {
            cin >> nums[j];
            s += nums[j];
        }

        if (n == 1 || n == 2)
        {
            ans[i] = -1;
            continue;
        }

        sort(nums.begin(), nums.end());

        int x = n * 2 * nums[n / 2] - s;

        if (x < 0)
            ans[i] = 0;
        else
            ans[i] = x + 1;
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;

    return 0;
}