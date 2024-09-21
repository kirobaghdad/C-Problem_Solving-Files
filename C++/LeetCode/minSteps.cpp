#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    long long solve(int n, string t = "A", string copy = "")
    {
        if (dp[n - t.length() + 1][copy.size()] != -1)
        {
            cout << "test" << endl;
            return dp[n - t.length() + 1][copy.size()];
        }

        if (t.length() == n)
            return dp[n - t.length() + 1][copy.size()] = 0;

        long long a = 1e9, b = 1e9;

        if ((t + t).size() <= n)
            a = 2 + solve(n, t + t, t);

        if (copy != "")
            if ((t + copy).size() <= n)
                b = 1 + solve(n, t + copy, copy);

        return dp[n - t.length() + 1][copy.size()] = min(a, b);
    }

    int minSteps(int n)
    {
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        dp[0][1] = 0;
        dp[1][1] = 0;

        return solve(n);
    }
};

int main()
{
    Solution s;

    cout << s.minSteps(1);
    return 0;
}