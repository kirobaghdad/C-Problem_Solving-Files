#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Convert to DP - 1D
    vector<int> dp;
    int m;

    int solve(int n, int i = 0, int j = 0, int r = 0)
    {
        if (i == j && i == n)
            return 1;

        if (i > n || j > n)
            return 0;

        if (i == j && dp[r] != -1)
            return dp[r];

        long long a = 0;

        if (i == j)
        {
            a += solve(n, i + 1, j + 1, r + 1) % m;
            a += solve(n, i + 2, j + 1, r + 1) % m;
            a += solve(n, i + 1, j + 2, r + 1) % m;
            a += solve(n, i + 2, j + 2, r + 2) % m;
        }
        else
        {
            if (i > j)
            {
                a += solve(n, i, j + 2, r + 1) % m;
                a += solve(n, i + 1, j + 2, r + 2) % m;
            }
            else
            {
                a += solve(n, i + 2, j, r + 1) % m;
                a += solve(n, i + 2, j + 1, r + 2) % m;
            }
        }

        if (i == j)
            return dp[r] = a % m;

        return a;
    }

    int numTilings(int n)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        dp = vector<int>(n, -1);
        m = 1e9 + 7;

        return solve(n);
    }
};

int main()
{

    return 0;
}