#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> nums)
    {
        int ans = 0;
        vector<int> dp(nums.size(), 0);

        int l = 1;
        int diff = INT_MIN;

        for (int i = 1; i < nums.size(); i++)
        {
            if (l == 1)
            {
                l++;
                diff = nums[i] - nums[i - 1];
            }
            else
            {
                if (diff == nums[i] - nums[i - 1])
                {
                    l++;
                    dp[i] = dp[i - 1] + l - 2;
                }
                else
                {
                    ans += dp[i - 1];
                    l = 2;
                    diff = nums[i] - nums[i - 1];
                }
            }

            if (i == nums.size() - 1)
                ans += dp[i];
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.numberOfArithmeticSlices({1, 2, 3, 4, 7, 10, 13, 16, 17, 18});

    return 0;
}