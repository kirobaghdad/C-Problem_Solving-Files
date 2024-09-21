#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<bool>> isVisited;

    void solve(vector<vector<char>> &grid, int i, int j)
    {
        // if (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size())
        // {
        // if (grid[i][j] == '1' && !isVisited[i][j])
        isVisited[i][j] = 1;
        // }
        // else
        //     return;

        if (j + 1 < grid[0].size() && grid[i][j + 1] == '1' && !isVisited[i][j + 1])
            solve(grid, i, j + 1);
        if (j - 1 >= 0 && grid[i][j - 1] == '1' && !isVisited[i][j - 1])
            solve(grid, i, j - 1);

        if (i + 1 < grid.size() && grid[i + 1][j] == '1' && !isVisited[i + 1][j])
            solve(grid, i + 1, j);
        if (i - 1 >= 0 && grid[i - 1][j] == '1' && !isVisited[i - 1][j])
            solve(grid, i - 1, j);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int ans = 0;

        isVisited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), 0));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!isVisited[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    solve(grid, i, j);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;

    vector<vector<char>> temp = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };

    cout << s.numIslands(temp);
    return 0;
}