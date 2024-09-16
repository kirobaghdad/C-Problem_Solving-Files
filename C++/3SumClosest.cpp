#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> nums, int target)
    {
        int temp = 0;

        sort(nums.begin(), nums.end());

        temp += nums[0] + nums[1] + nums[2];

        for (int i = 3; i < nums.size(); i++)
        {
            if (abs(target - (temp + nums[i] - nums[i - 3])) < abs(temp - target))
                temp = temp + nums[i] - nums[i - 3];
        }

        return temp;
    }
};

int main()
{
    Solution s;

    cout << s.threeSumClosest({4, 0, 5, -5, 3, 3, 0, -4, -5}, -2);

    return 0;
}