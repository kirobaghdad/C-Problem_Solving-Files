#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    int solve(vector<vector<int>> &grid, int i = 0, int j = 0)
    {
        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        if (i + 1 < grid.size())
        {
            for (int k = 0; k < grid[0].size(); k++)
            {
                if (k != j)
                    dp[i][j] = min(dp[i][j], grid[i][j] + solve(grid, i + 1, k));
            }

            return dp[i][j];
        }

        return dp[i][j] = grid[i][j];
    }

    int minFallingPathSum(vector<vector<int>> grid)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), INT_MAX));

        int ans = INT_MAX;

        for (int j = 0; j < grid[0].size(); j++)
        {
            ans = min(ans, solve(grid, 0, j));
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.minFallingPathSum({{2, 2, 1, 2, 2}, {2, 2, 1, 2, 2}, {2, 2, 1, 2, 2}, {2, 2, 1, 2, 2}, {2, 2, 1, 2, 2}});
    return 0;
}