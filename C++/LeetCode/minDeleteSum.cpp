#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    int solve(string s1, string s2, int i = 0, int j = 0)
    {
        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == s1.size())
        {
            int ans = 0;
            for (int k = j; k < s2.size(); k++)
                ans += s2[k];

            return dp[i][j] = ans;
        }

        if (j == s2.size())
        {
            int ans = 0;
            for (int k = i; k < s1.size(); k++)
                ans += s1[k];

            return dp[i][j] = ans;
        }
        if (s1[i] == s2[j])
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);

        return dp[i][j] = min(s1[i] + solve(s1, s2, i + 1, j), s2[j] + solve(s1, s2, i, j + 1));
    }

    int minimumDeleteSum(string s1, string s2)
    {
        dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        return solve(s1, s2);
    }
};

int main()
{
    Solution s;

    cout << s.minimumDeleteSum("delete", "leet");

    return 0;
}