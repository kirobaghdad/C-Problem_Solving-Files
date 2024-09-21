#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(const vector<vector<int>> &grid, int i, int row = 0)
    {
        if (row == grid.size())
            return i;

        if (grid[row][i] == 1 && (i + 1 < grid[0].size() && grid[row][i + 1] == 1))
        {
            return solve(grid, i + 1, row + 1);
        }

        if (grid[row][i] == -1 && (i - 1 >= 0 && grid[row][i - 1] == -1))
            return solve(grid, i - 1, row + 1);

        return -1;
    }

    vector<int> findBall(vector<vector<int>> &grid)
    {
        vector<int> ans(grid[0].size(), -1);

        for (int i = 0; i < grid[0].size(); i++)
        {
            ans[i] = solve(grid, i);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> grid = {{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}};
    vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}, {1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}};

    vector<int> ans = s.findBall(grid);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}