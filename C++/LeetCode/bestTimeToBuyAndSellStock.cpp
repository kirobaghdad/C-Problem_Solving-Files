#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> prices, int fee)
    {
        int profit = 0;
        int stocks = -prices[0] - fee;

        for (int i = 1; i < prices.size(); i++)
        {
            // Sell or not to sell that is the question
            profit = max(profit, prices[i] + stocks);

            // Buy or not to buy that is the question
            stocks = max(stocks, profit - prices[i] - fee);
        }

        return profit;
    }
};
int main()
{
    Solution s;

    cout << s.maxProfit({1, 3, 2, 8, 4, 9}, 2);

    return 0;
}