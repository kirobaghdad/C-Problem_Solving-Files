#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string optimalDivision(vector<int> &nums)
    {
        vector<float> dp(nums.size(), 0);
        dp[0] = nums[0];

        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i - 1] / (nums[i] + 0.0) > dp[i - 1] / (nums[i] + 0.0))
            {
                dp[i] = nums[i - 1] / (nums[i] + 0.0);
            }
            else
                dp[i] = dp[i - 1] / (nums[i] + 0.0);
        }
    }
};

int main()
{

    return 0;
}