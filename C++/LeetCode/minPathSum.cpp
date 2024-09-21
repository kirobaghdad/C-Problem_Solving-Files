#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    int solve(const vector<vector<int>> &grid, int sum = 0, int i = 0, int j = 0)
    {
        sum += grid[i][j];

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            if (sum > dp[i][j])
                return dp[i][j];
            else
                return dp[i][j] = sum;
        }

        int a = INT_MAX, b = INT_MAX;

        if (sum >= dp[i][j])
            return INT_MAX;

        // Down
        if (i + 1 < grid.size())
        {

            a = solve(grid, sum, i + 1, j);
        }

        // Right
        if (j + 1 < grid[0].size())
            b = solve(grid, sum, i, j + 1);

        return dp[i][j] = min(a, b);
    }

    int minPathSum(vector<vector<int>> grid)
    {
        dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        return solve(grid);
    }
};

int main()
{

    Solution s;

    // cout << s.minPathSum({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}});
    cout << s.minPathSum({{1, 2, 3}, {4, 5, 6}});

    return 0;
}