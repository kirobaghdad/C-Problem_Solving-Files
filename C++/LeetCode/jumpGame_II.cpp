#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp;
    int temp;

    int solve(vector<int> &nums, int i = 0)
    {
        if (i == nums.size() - 1 || dp[i] != INT_MAX)
        {
            return dp[i];
        }

        int j = min(nums[i], (int)nums.size() - i - 1);

        for (; j >= 1; j--)
        {
            temp = solve(nums, i + j);

            if (temp == INT_MAX)
                dp[i] = min(dp[i], INT_MAX);
            else
                dp[i] = min(dp[i], 1 + temp);
        }

        return dp[i];
    }

    int jump(vector<int> nums)
    {
        dp = vector<int>(nums.size(), INT_MAX);
        dp[nums.size() - 1] = 0;

        return solve(nums);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution s;

    cout << s.jump({2, 3, 1, 1, 4});

    return 0;
}