#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> ans;

    // d = 0 right, d = 1 left, d = 2  down, d = 3 up
    void solve(vector<vector<int>> &grid, int d = 0, int i = 0, int j = 0)
    {
        ans.push_back(grid[i][j]);
        if (grid[i][j] == 0)
            grid[i][j] = 1000;
        else
            grid[i][j] *= 1000;

        if (d == 0)
        {
            if (j + 1 < grid[0].size() && grid[i][j + 1] < 1000)
                solve(grid, d, i, j + 1);
            else
            {
                if (i + 1 < grid.size() && grid[i + 1][j] < 1000)
                    solve(grid, 2, i + 1, j);
            }
        }

        if (d == 1)
        {
            if (j - 1 >= 0 && grid[i][j - 1] < 1000)
                solve(grid, d, i, j - 1);

            else
            {
                if (i - 1 < grid.size() && grid[i - 1][j] < 1000)
                    solve(grid, 3, i - 1, j);
            }
        }

        if (d == 2)
        {
            if (i + 1 < grid.size() && grid[i + 1][j] < 1000)
                solve(grid, d, i + 1, j);

            else
            {
                if (j - 1 >= 0 && grid[i][j - 1] < 1000)
                    solve(grid, 1, i, j - 1);
            }
        }

        if (d == 3)
        {
            if (i - 1 >= 0 && grid[i - 1][j] < 1000)
                solve(grid, d, i - 1, j);
            else
            {
                if (j + 1 < grid[0].size() && grid[i][j + 1] < 1000)
                    solve(grid, 0, i, j + 1);
            }
        }
    }

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        solve(matrix);

        return ans;
    }
};

int main()
{

    return 0;
}