#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumTripletValue(vector<int> nums)
    {
        long long ans = 0;

        // begin max
        vector<int> bMax(nums.size());
        bMax[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            bMax[i] = max(nums[i], bMax[i - 1]);
        }

        // end max
        vector<int> eMax(nums.size());
        vector<int> eMin(nums.size());

        eMax[nums.size() - 1] = nums[nums.size() - 1];
        eMin[nums.size() - 1] = nums[nums.size() - 1];

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            eMax[i] = max(nums[i], eMax[i + 1]);
        }

        for (int i = 1; i < nums.size() - 1; i++)
        {
            ans = max(ans, (bMax[i - 1] - nums[i]) * (long long)eMax[i + 1]);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.maximumTripletValue({1000000, 1, 1000000});
    return 0;
}