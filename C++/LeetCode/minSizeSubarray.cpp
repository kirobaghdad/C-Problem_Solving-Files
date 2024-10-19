#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> prefix(nums.size() + 1, 0);

        for (int i = 1; i < prefix.size(); i++)
        {
            prefix[i] = nums[i - 1] + prefix[i - 1];
        }

        int ans = INT_MAX;

        int iPrefix = 0;
        int jPrefix = nums[0];

        int j = 1;

        for (int i = 1; i < nums.size() + 1; i++)
        {

            while (j < nums.size() && jPrefix - iPrefix < target)
            {
                jPrefix += nums[j];
                j++;
            }

            if (j == nums.size() + 1)
                break;

            if (jPrefix - iPrefix >= target)
                ans = min(ans, j - i + 1);
            else
                break;

            iPrefix += nums[i - 1];
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

int main()
{
    Solution s;

    cout << s.minSubArrayLen(11, {1, 1, 1, 1, 1, 1, 1, 1});

    return 0;
}