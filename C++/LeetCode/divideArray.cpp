#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> nums, int k)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i += 3)
        {
            vector<int> temp(nums.begin() + i, nums.begin() + i + 3);
            ans.push_back(temp);

            if (ans[i / 3][2] - ans[i / 3][0] > k)
                return vector<vector<int>>();
        }

        return ans;
    }
};

int main()
{
    Solution s;
    s.divideArray({1, 3, 4, 8, 7, 9, 3, 5, 1}, 2);

    return 0;
}