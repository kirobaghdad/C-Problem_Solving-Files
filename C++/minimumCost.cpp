#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCost(vector<int> cost)
    {
        int ans = 0;

        sort(cost.begin(), cost.end());

        for (int i = cost.size() - 1; i >= 0; i--)
        {
            ans += cost[i];

            if (i - 1 >= 0)
            {
                ans += cost[i - 1];
            }

            i -= 2;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.minimumCost({1, 2, 3});
    return 0;
}