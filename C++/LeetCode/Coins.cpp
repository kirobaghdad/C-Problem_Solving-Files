#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // 1 comb: no coins for no amount
        for (int c : coins)
        {
            for (int i = 1; i <= amount; i++)
                if (i - c >= 0)
                    dp[i] += dp[i - c];
        }
        return dp[amount];
    }
};

int main()
{
    Solution s;
    cout << s.change(5, {1, 2, 5});

    return 0;
}