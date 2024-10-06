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

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        nums = vector<int>(n);

        for (int j = 0; j < n; j++)
        {
            cin >> nums[j];
        }

        sort(nums.begin(), nums.end());

        while (nums.size() > 1)
        {
            nums[0] = (nums[0] + nums[1]) / 2;
            nums.erase(nums.begin() + 1);
        }

        ans[i] = nums[0];
    }

    for (int i = 0; i < t; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}