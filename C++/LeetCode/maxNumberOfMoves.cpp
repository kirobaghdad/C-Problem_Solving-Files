#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    int solve(vector<vector<int>> &grid, int i, int j)
    {

        if (dp[i][j] != 0)
            return dp[i][j];

        int temp = 0;

        if (j + 1 < grid[0].size())
        {
            // same row
            if (grid[i][j] < grid[i][j + 1])
                temp = max(temp, 1 + solve(grid, i, j + 1));

            if (i + 1 < grid.size())
                if (grid[i][j] < grid[i + 1][j + 1])
                    temp = max(temp, 1 + solve(grid, i + 1, j + 1));

            if (i - 1 >= 0)
                if (grid[i][j] < grid[i - 1][j + 1])
                    temp = max(temp, 1 + solve(grid, i - 1, j + 1));
        }
        else
            return dp[i][j] = 0;

        return dp[i][j] = temp;
    }

    int maxMoves(vector<vector<int>> grid)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), 0));

        int ans = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            ans = max(ans, solve(grid, i, 0));
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.maxMoves({{2, 3, 4, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}});

    return 0;
}