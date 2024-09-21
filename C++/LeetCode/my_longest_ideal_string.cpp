#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int dp[150] = {};
        int res = 0;

        for (auto &i : s)
        {
            for (int j = i - k; j <= i + k; j++)
                dp[i] = max(dp[i], dp[j]);
            res = max(res, ++dp[i]);
        }
        return res;
    }
};

int main()
{

    Solution s;

    cout << s.longestIdealString("acfgbd", 2);

    return 0;
}