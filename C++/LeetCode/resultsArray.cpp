#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> resultsArray(vector<int> nums, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        if (nums.size() == 1 || k == 1)
            return nums;

        vector<int> ans;

        for (int i = 1; i < k; i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                ans.push_back(-1);
                break;
            }
            else if (i == k - 1)
                ans.push_back(nums[i]);
        }

        for (int i = k; i < nums.size(); i++)
        {
            if (ans.back() != -1 && nums[i] == nums[i - 1] + 1)
                ans.push_back(nums[i]);
            else
            {
                // recompute
                for (int l = i - k + 2; l <= i; l++)
                {
                    if (nums[l] != nums[l - 1] + 1)
                    {
                        ans.push_back(-1);
                        break;
                    }
                    else if (l == i)
                        ans.push_back(nums[l]);
                }
            }
        }

        return ans;
    }
};
int main()
{
    Solution s;

    s.resultsArray({3, 2, 3, 2, 3, 2}, 2);
    return 0;
}