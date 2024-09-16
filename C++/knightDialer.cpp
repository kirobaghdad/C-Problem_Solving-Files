#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<int, vector<int>> dial;

    // [len][last]
    vector<vector<int>> dp;

    int modulo = 1000000007;

    int solve(int n, int oN, int last = -1)
    {
        if (n == 0)
            return dp[n][last] = 1;

        int ans = 0;

        if (n == oN)
        {
            for (int j = 0; j <= 9; j++)
            {
                ans = (ans + solve(n - 1, oN, j)) % modulo;
            }
        }
        else
        {
            if (dp[n][last] != -1)
                return dp[n][last];

            for (auto it : dial[last])
            {
                ans = (ans + solve(n - 1, oN, it)) % modulo;
            }

            dp[n][last] = ans;
        }

        return ans;
    }

    int knightDialer(int n)
    {
        dial[0] = {4, 6};
        dial[1] = {6, 8};
        dial[2] = {7, 9};
        dial[3] = {4, 8};
        dial[4] = {0, 3, 9};
        dial[5] = {};
        dial[6] = {0, 1, 7};
        dial[7] = {2, 6};
        dial[8] = {1, 3};
        dial[9] = {2, 4};

        dp = vector<vector<int>>(n + 1, vector<int>(10, -1));

        return solve(n, n);
    }
};

int main()
{
    Solution s;

    cout << s.knightDialer(3131);

    return 0;
}