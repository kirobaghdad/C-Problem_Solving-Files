#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSplits(string s)
    {
        int ans = 0;

        set<char> letters;

        vector<int> dp(s.size(), 1);

        letters.insert(s[s.size() - 1]);

        for (int i = s.size() - 2; i >= 0; i--)
        {
            if (letters.count(s[i]) == 0)
            {
                letters.insert(s[i]);
                dp[i] = dp[i + 1] + 1;
            }
            else
            {
                dp[i] = dp[i + 1];
            }
        }

        letters.clear();

        int distLeft = 1;
        letters.insert(s[0]);

        for (int i = 1; i < s.size(); i++)
        {
            if (dp[i] == distLeft)
                ans++;

            if (letters.count(s[i]) == 0)
            {
                letters.insert(s[i]);
                distLeft++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.numSplits("abcd");

    return 0;
}