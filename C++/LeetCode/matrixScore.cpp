#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int matrixScore(vector<vector<int>> grid)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        for (int i = 0; i < grid.size(); i++)
        {
            if (grid[i][0] == 0)
            {
                for (int j = 0; j < grid[0].size(); j++)
                    grid[i][j] = !grid[i][j];
            }
        }

        for (int j = 0; j < grid[0].size(); j++)
        {
            int ones = 0;

            for (int i = 0; i < grid.size(); i++)
            {
                ones += grid[i][j];
            }

            if (ones < grid.size() - ones)
            {
                for (int i = 0; i < grid.size(); i++)
                {
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                ans += pow(2, grid[0].size() - j - 1) * grid[i][j];
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.matrixScore({{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}});

    return 0;
}