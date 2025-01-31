#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    void solve(vector<int> &candidates, int target, vector<int> &curr, int i = 0, int sum = 0)
    {
        if (i == candidates.size() || sum > target)
            return;

        curr.push_back(candidates[i]);
        sum += candidates[i];

        if (target == sum)
        {
            ans.push_back(curr);
            curr.pop_back();
        }
        else
        {
            solve(candidates, target, curr, i, sum);
            curr.pop_back();
            sum -= candidates[i];
            solve(candidates, target, curr, i + 1, sum);
        }
    }

    vector<vector<int>> combinationSum(vector<int> candidates, int target)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        // using recursion
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        solve(candidates, target, curr);

        return ans;
    }
};

int main()
{
    Solution s;

    s.combinationSum({2}, 1);

    return 0;
}