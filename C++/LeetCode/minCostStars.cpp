#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp;

    int minCost(vector<int> cost, int s)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        if (s > cost.size())
            return 0;

        if (dp[s] != INT_MAX)
            return dp[s];

        int add = s == 0 ? 0 : cost[s - 1];
        return dp[s] = add + min(minCost(cost, s + 1), minCost(cost, s + 2));
    }

    int minCostClimbingStairs(vector<int> cost)
    {
        dp = vector<int>(cost.size() + 1, INT_MAX);

        minCost(cost, 0);

        return dp[0];
    }
};

int main()
{
    Solution s;

    cout << s.minCostClimbingStairs({10, 15, 20});

    return 0;
}