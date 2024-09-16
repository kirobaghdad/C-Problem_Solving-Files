#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                if (prices[j] - prices[i] > maxProfit)
                    maxProfit = prices[j] - prices[i];
            }
        }

        return maxProfit;
    }
};

int main()
{
    Solution s;
    vector<int> prices = {7, 6, 4, 3, 1};

    cout << s.maxProfit(prices);

    return 0;
}