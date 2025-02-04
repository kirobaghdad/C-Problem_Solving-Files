#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    void solve(vector<int> &can, int target, vector<int> &curr, int index = 0, int sum = 0)
    {

        // take or not take that is the question
        // take
        // curr.push_back(can[i]);
        // sum += can[i];

        if (sum == target)
        {
            ans.push_back(curr);
        }
        else if (sum > target)
            return;
        else
        {
            for (int i = index; i < can.size() && (target - sum) >= can[i]; i++)
            {
                if (i > index && can[i] == can[i - 1])
                    continue;
                curr.push_back(can[i]);
                solve(can, target, curr, i + 1, sum + can[i]);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> candidates, int target)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> curr;

        sort(candidates.begin(), candidates.end());

        solve(candidates, target, curr);

        return ans;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> ans = s.combinationSum2({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 30);

    return 0;
}