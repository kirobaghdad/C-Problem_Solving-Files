#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int dp[150] = {}, res = 0;
        for (auto &i : s)
        {
            for (int j = i - k; j <= i + k; ++j)
                dp[i] = max(dp[i], dp[j]);
            res = max(res, ++dp[i]);
        }
        return res;
    }
};

int main()
{
    Solution s;

    cout << s.longestIdealString("eduktdb", 15);

    return 0;
}