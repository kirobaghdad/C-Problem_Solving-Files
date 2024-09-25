#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int count = 0;
        int total = 0;

        queue<pair<int, int>> rotten;

        int m = grid.size();
        int n = grid[0].size();

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (grid[i][j] == 2)
                {
                    rotten.push({i, j});
                    count++;
                    total++;
                }

                if (grid[i][j] == 1)
                    total++;
            }
        }

        pair<int, int> t;

        int time = 0;
        bool found = 0;
        int s;

        while (true)
        {
            found = 0;
            s = rotten.size();
            while (s)
            {
                t = rotten.front();
                rotten.pop();

                if (t.first > 0 && grid[t.first - 1][t.second] == 1)
                {
                    rotten.push({t.first - 1, t.second});
                    grid[t.first - 1][t.second] = 2;
                    count++;
                    found = 1;
                }

                if (t.first < m - 1 && grid[t.first + 1][t.second] == 1)
                {
                    rotten.push({t.first + 1, t.second});
                    grid[t.first + 1][t.second] = 2;
                    count++;
                    found = 1;
                }

                if (t.second > 0 && grid[t.first][t.second - 1] == 1)
                {
                    rotten.push({t.first, t.second - 1});
                    grid[t.first][t.second - 1] = 2;
                    count++;
                    found = 1;
                }

                if (t.second < n - 1 && grid[t.first][t.second + 1] == 1)
                {
                    rotten.push({t.first, t.second + 1});
                    grid[t.first][t.second + 1] = 2;
                    count++;
                    found = 1;
                }
                s--;
            }

            if (found)
                time++;
            else
                break;
        }

        return count == total ? time : -1;
    }
};

int main()
{

    return 0;
}