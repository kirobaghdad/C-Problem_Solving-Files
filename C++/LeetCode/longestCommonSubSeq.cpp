#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Convert To DP
    vector<vector<int>> dp;

    int solve(string &text1, string &text2, int i = 0, int j = 0)
    {

        if (i == text1.size() || j == text2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i] == text2[j])
            return dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1);

        int a = solve(text1, text2, i + 1, j);
        a = max(a, solve(text1, text2, i, j + 1));

        return dp[i][j] = a;
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        dp = vector<vector<int>>(text1.size(), vector<int>(text2.size(), -1));

        return solve(text1, text2);
    }
};

int main()
{

    return 0;
}