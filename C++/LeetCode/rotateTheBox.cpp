#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<vector<char>> ans = vector<vector<char>>(box[0].size(), vector<char>(box.size(), 0));

        int lastObstacle;

        for (int i = 0; i < box.size(); i++)
        {
            lastObstacle = box[0].size() - 1;

            for (int j = box[0].size() - 1; j >= 0; j--)
            {
                if (box[i][j] == '#')
                {
                    box[i][j] = '.';
                    box[i][lastObstacle--] = '#';
                }
                else if (box[i][j] == '*')
                {
                    lastObstacle = j - 1;
                }
            }

            for (int j = box[0].size() - 1; j >= 0; j--)
                ans[j][box.size() - i - 1] = box[i][j];
        }

        return ans;
    }
};
int main()
{

    return 0;
}