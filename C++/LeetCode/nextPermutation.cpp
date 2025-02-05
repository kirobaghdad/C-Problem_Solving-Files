#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        bool found = false;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            int temp = -1;

            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] > nums[i] && (temp == -1 || nums[j] <= nums[temp]))
                    temp = j;
            }

            if (temp != -1)
            {
                swap(nums[i], nums[temp]);

                // sort
                sort(nums.begin() + i + 1, nums.end());

                return;
            }
        }

        reverse(nums.begin(), nums.end());
        return;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1};

    s.nextPermutation(nums);

    return 0;
}