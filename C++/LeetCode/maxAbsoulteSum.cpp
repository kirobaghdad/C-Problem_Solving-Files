#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxAbsoluteSum(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int minim = 0;
        int maxim = 0;
        int ans = 0;

        vector<int> pre(nums.size() + 1, 0);

        for (int i = 1; i < pre.size(); i++)
        {
            pre[i] = nums[i - 1] + pre[i - 1];

            ans = max(abs(ans), abs(pre[i] - minim));
            ans = max(abs(ans), abs(pre[i] - maxim));

            minim = min(pre[i], minim);
            maxim = max(pre[i], maxim);
        }

        return ans;
    }
};
int main()
{
    Solution s;

    cout << s.maxAbsoluteSum({2, -5, 1, -4, 3, -2});

    return 0;
}