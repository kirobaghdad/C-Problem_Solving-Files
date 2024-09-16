#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    void solve(const vector<vector<int>> &mat, int i = 0, int j = 0, int nearestZero = 1e6)
    {
        if (i < 0 || j < 0 || i == mat.size() || j == mat[0].size())
            return;

        if (mat[i][j] == 0)
        {
            ans[i][j] = 0;
            solve(mat, i + 1, j, 1);
            solve(mat, i, j + 1, 1);
            // solve(mat, i - 1, j, 1);
            // solve(mat, i, j - 1, 1);
        }
        else
        {
            ans[i][j] = min(ans[i][j], nearestZero);

            solve(mat, i + 1, j, nearestZero + 1);
            solve(mat, i, j + 1, nearestZero + 1);
            // solve(mat, i - 1, j, nearestZero + 1);
            // solve(mat, i, j - 1, nearestZero + 1);
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> mat)
    {
        ans = vector<vector<int>>(mat.size(), vector<int>(mat[0].size(), 1e6));

        solve(mat);

        return ans;
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> ans = s.updateMatrix({{0, 0, 0}, {0, 1, 0}, {1, 1, 1}});
    vector<vector<int>> ans = s.updateMatrix({{0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 1, 0}, {1, 0, 1, 1, 1}, {1, 0, 0, 0, 1}});

    return 0;
}