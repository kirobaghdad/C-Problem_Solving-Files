#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> prices, int fee)
    {
        int n = prices.size();
        int hold = -prices[0]; // Maximum profit when holding a stock
        int notHold = 0;       // Maximum profit when not holding a stock

        for (int i = 1; i < n; i++)
        {
            int prevHold = hold;
            hold = max(hold, notHold - prices[i]);
            notHold = max(notHold, prevHold + prices[i] - fee);
        }

        return notHold;
    }
};

int main()
{
    Solution s;

    cout << s.maxProfit({1, 3, 2, 8, 4, 9}, 2);

    return 0;
}