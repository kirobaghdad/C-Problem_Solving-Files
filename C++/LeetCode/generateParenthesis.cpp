#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};

        for (int i = 1; i <= n; i++)
        {
            set<string> x;

            vector<string> temp = dp[i - 1];
            vector<string> temp1;

            for (auto it : temp)
            {
                it.insert(0, "(");
                it.insert(it.size(), ")");
                x.insert(it);
            }

            for (int j = i - 1; j >= i - j; j--)
            {
                temp = dp[j];
                temp1 = dp[i - j];

                for (auto it : temp)
                {

                    for (auto it1 : temp1)
                    {
                        x.insert(it + it1);
                        x.insert(it1 + it);
                    }
                }
            }

            if (i > 1)
                dp[i].insert(dp[i].end(), dp[i - 1].begin(), dp[i - 1].end());

            dp[i] = vector<string>(x.begin(), x.end());
        }

        return dp[n];
    }
};

int main()
{
    Solution s;

    vector<string> ans = s.generateParenthesis(3);

    for (auto it : ans)
        cout << it << endl;

    return 0;
}