#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> matrix)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 0;

        vector<int> dp0, dp1(matrix[0].size(), 0);

        int a;

        for (int i = 0; i < matrix.size(); i++)
        {
            dp1 = vector<int>(matrix[i].size(), 0);

            for (int j = 0; j < matrix[0].size(); j++)
            {
                a = 0;

                if (matrix[i][j])
                {
                    if (i > 0 && j > 0)
                    {
                        a = min(dp0[j - 1], dp0[j]);
                        a = min(a, dp1[j - 1]);
                    }

                    dp1[j] = 1 + a;
                }

                ans += dp1[j];
            }

            dp0 = dp1;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.countSquares({{0, 1, 1, 1},
                            {1, 1, 1, 1},
                            {0, 1, 1, 1}});
    return 0;
}