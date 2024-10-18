#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<int, int> ans;

    void solve(vector<int> &nums, int i = 0, int s = 0)
    {

        if (nums.size() == i)
            return;

        solve(nums, i + 1, s);

        s = s | nums[i];
        ans[s]++;

        solve(nums, i + 1, s);
    }

    int countMaxOrSubsets(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        solve(nums);

        return ans.rbegin()->second;
    }
};

int main()
{
    Solution s;

    cout << s.countMaxOrSubsets({3, 2, 1, 5});

    return 0;
}