#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp;

    int numTrees(int n)
    {
        if (n == 0)
            return 1;

        if (dp.size() == 0)
        {
            dp = vector<int>(n, 0);
            dp[0] = 1;
        }

        if (dp[n - 1] > 0)
            return dp[n - 1];

        for (int i = 0; i < n; i++)
        {
            dp[n - 1] += numTrees(i) * numTrees(n - i - 1);
        }

        return dp[n - 1];
    }
};

int main()
{
    Solution s;

    cout << s.numTrees(1);

    return 0;
}