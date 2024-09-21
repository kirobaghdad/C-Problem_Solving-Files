#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<int, int> dp;

    int getPower(int v)
    {
        if (dp.count(v) != 0)
            return dp[v];

        if (v % 2 == 0)
            return dp[v] = 1 + getPower(v / 2);
        else
            return dp[v] = 1 + getPower(3 * v + 1);
    }

    int getKth(int lo, int hi, int k)
    {
        dp[0] = 0;
        dp[1] = 0;

        multimap<int, int> powers;

        for (int i = lo; i <= hi; i++)
        {
            getPower(i);
        }

        for (int i = lo; i <= hi; i++)
        {
            powers.insert(pair<int, int>(dp[i], i));
        }

        int i = 0;

        int ans = powers.begin()->second;

        for (auto it : powers)
        {
            if (i != k)
            {
                ans = it.second;
                i++;
            }

            else
                break;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.getKth(7, 11, 4);

    return 0;
}