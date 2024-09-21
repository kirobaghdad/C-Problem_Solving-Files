#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> dp(prices.size(), 0);

        int term = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            dp[i] = dp[i - 1];

            dp[i] = max(dp[i], prices[i] - term);

            term = min(term, prices[i] - dp[i - 1]);
            // for(int j = 0; j < i; j++){
            //     if(j >= 1)
            //         dp[i] = max(dp[i], prices[i] - prices[j] + dp[j-1]);
            //     else
            //         dp[i] = max(dp[i], prices[i] - prices[j]);

            // }
        }

        return dp[prices.size() - 1];
    }
};

int main()
{

    vector<int> prices = {5, 4, 3, 2, 1};

    Solution s;

    cout << s.maxProfit(prices);

    return 0;
}