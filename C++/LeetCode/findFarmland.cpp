#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<bool>> isVisited;

    void solve(vector<vector<int>> &land, int i, int j)
    {
        isVisited[i][j] = 1;
        if (ans[ans.size() - 1][2] < i || ans[ans.size() - 1][3] < j)
        {
            ans[ans.size() - 1][2] = i;
            ans[ans.size() - 1][3] = j;
        }

        if (j + 1 < land[0].size() && land[i][j + 1] == 1 && !isVisited[i][j + 1])
            solve(land, i, j + 1);
        if (j - 1 >= 0 && land[i][j - 1] == 1 && !isVisited[i][j - 1])
            solve(land, i, j - 1);

        if (i + 1 < land.size() && land[i + 1][j] == 1 && !isVisited[i + 1][j])
            solve(land, i + 1, j);
        if (i - 1 >= 0 && land[i - 1][j] == 1 && !isVisited[i - 1][j])
            solve(land, i - 1, j);
    }

    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        // isVisited = vector<vector<bool>>(land.size(), vector<bool>(land[0].size(), false));

        for (int i = 0; i < land.size(); i++)
        {
            for (int j = 0; j < land[0].size(); j++)
            {
                if (!(land[i][j] == 0 || (j > 0 && land[i][j - 1] == 1) || (i > 0 && land[i - 1][j] == 1)))
                {
                    int bottomRightY = i;
                    int bottomRightX = j;

                    while (bottomRightX < land[0].size() && land[i][bottomRightX])
                    {
                        bottomRightX++;
                    }

                    bottomRightX--;

                    while (bottomRightY < land.size() && land[bottomRightY][j])
                    {
                        bottomRightY++;
                    }

                    bottomRightY--;

                    ans.push_back({i, j, bottomRightY, bottomRightX});

                    // solve(land, i, j);
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> nums = {{1, 0, 0}, {0, 1, 1}, {0, 1, 1}};

    Solution s;

    vector<vector<int>> ans = s.findFarmland(nums);

    for (int i = 0; i < ans.size(); i++)

    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}