#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        vector<int> dp(n + 1, 0); // Correct Num
        dp[0] = 1;
        if (n > 0)
            dp[1] = 10;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = pow(10, i) - (dp[i - 1] * (i - 1) + (pow(10, i - 1) - dp[i - 1]) * 10 - 1);
        }

        return dp[n];
    }
};

int main()
{
    Solution s;

    cout << s.countNumbersWithUniqueDigits(0);
    return 0;
}