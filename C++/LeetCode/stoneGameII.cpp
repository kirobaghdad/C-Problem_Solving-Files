#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    int solve(const vector<int> &piles, bool alice = 1, int i = 0, int M = 1)
    {
        if (i >= piles.size())
            return 0;

        if (dp[i][M] != -1)
        {
            return dp[i][M];
        }

        int sum = 0;

        for (int j = 1; j <= 2 * M && i + j - 1 < piles.size(); j++)
        {
            if (alice)
            {
                sum += piles[i + j - 1];

                dp[i][j] = max(dp[i][j], sum + solve(piles, !alice, i + j, max(M, j)));
            }
            else
            {
                dp[i][j] = min(dp[i][j], solve(piles, !alice, i + j, max(M, j)));
            }
        }

        return *max_element(dp[i].begin(), dp[i].end());
    }

    int stoneGameII(vector<int> &piles)
    {
        dp = vector<vector<int>>(piles.size() + 1, vector<int>(piles.size() + 1, -1));

        int ans = solve(piles);

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> piles = {2, 7, 9, 4, 4};

    cout << s.stoneGameII(piles);
    return 0;
}