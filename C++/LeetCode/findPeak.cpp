#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int s, int e)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int m = (e + s) / 2;

        if (m == 0 || m == nums.size() - 1)
            return -1;

        if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
            return m;

        if (s == m)
            return -1;

        int a = solve(nums, s, m);

        if (a != -1)
            return a;

        else
            return solve(nums, m + 1, e);
    }

    int findPeakElement(vector<int> nums)
    {
        nums.insert(nums.begin(), INT_MIN);
        nums.insert(nums.end(), INT_MIN);

        int ans = solve(nums, 0, nums.size() - 1);

        if (ans == -1)
            return 0;
        else
            return ans - 1;
    }
};

int main()
{
    Solution s;

    cout << s.findPeakElement({-2147483648});

    return 0;
}