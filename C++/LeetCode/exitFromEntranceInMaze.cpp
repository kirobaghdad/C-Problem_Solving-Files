#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        int i, j;

        int d;

        while (q.size())
        {
            i = q.front().first.first;
            j = q.front().first.second;
            d = q.front().second;

            if ((i == 0 || j == 0 || i == maze.size() - 1 || j == maze[0].size() - 1) && !(i == entrance[0] && j == entrance[1]))
                return d;

            q.pop();

            // up
            if (i > 0 && maze[i - 1][j] == '.')
            {
                q.push({{i - 1, j}, d + 1});
                maze[i - 1][j] = '+';
            }

            // down
            if (i < maze.size() - 1 && maze[i + 1][j] == '.')
            {
                q.push({{i + 1, j}, d + 1});
                maze[i + 1][j] = '+';
            }

            // right
            if (j < maze[0].size() - 1 && maze[i][j + 1] == '.')
            {
                q.push({{i, j + 1}, d + 1});
                maze[i][j + 1] = '+';
            }

            // left
            if (j > 0 && maze[i][j - 1] == '.')
            {
                q.push({{i, j - 1}, d + 1});
                maze[i][j - 1] = '+';
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}
