#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // perfix sum
    vector<int> productExceptSelf(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> pre(nums.size() + 1);
        vector<int> suf(nums.size() + 1);

        pre[0] = 1;

        for (int i = 1; i < nums.size() + 1; i++)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
        }

        suf[nums.size()] = 1;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            suf[i] = suf[i + 1] * nums[i];
        }

        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++)
            ans[i] = pre[i] * suf[i + 1];

        return ans;
    }
};

int main()
{
    Solution s;

    s.productExceptSelf({1, 2, 3, 4});

    return 0;
}