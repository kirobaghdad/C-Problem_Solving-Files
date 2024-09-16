#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void getFourSum(const vector<int> &nums, int target, set<vector<int>> &ans, vector<int> currentArr = vector<int>(), int currentSum = 0, int index = 0)
    {
        if (currentArr.size() == 4)
        {
            if (currentSum == target)
                ans.insert(currentArr);

            return;
        }

        for (int i = index; i < nums.size() - 4 + currentArr.size() + 1; i++)
        {
            currentSum += nums[i];
            currentArr.push_back(nums[i]);
            getFourSum(nums, target, ans, currentArr, currentSum, i + 1);
            currentSum -= nums[i];
            currentArr.pop_back();
        }
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> ans_set;
        vector<vector<int>> ans;
        if (nums.size() < 4)
            return ans;

        sort(nums.begin(), nums.end());

        getFourSum(nums, target, ans_set);
        ans.assign(ans_set.begin(), ans_set.end());

        return ans;
    }
};

int main()
{
    Solution s;

    int n;
    cin >> n;

    vector<int> nums = {-498, -492, -473, -455, -441, -412, -390, -378, -365, -359, -358, -326, -311, -305, -277, -265, -264, -256, -254, -240, -237, -234, -222, -211, -203, -201, -187, -172, -164, -134, -131, -91, -84, -55, -54, -52, -50, -27, -23, -4, 0, 4, 20, 39, 45, 53, 53, 55, 60, 82, 88, 89, 89, 98, 101, 111, 134, 136, 209, 214, 220, 221, 224, 254, 281, 288, 289, 301, 304, 308, 318, 321, 342, 348, 354, 360, 383, 388, 410, 423, 442, 455, 457, 471, 488, 488};

    // for (int i = 0; i < n; i++)
    //     cin >> nums[i];

    int target;
    cin >> target;

    vector<vector<int>> ans = s.fourSum(nums, target);

    cout << "test";

    return 0;
}