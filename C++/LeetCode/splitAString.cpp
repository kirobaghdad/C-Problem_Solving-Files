#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // USE Recursion

    int maxUniqueSplit(string s, int i = 0, set<string> strs = set<string>())
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 0;

        if (i == s.size())
            return strs.size();

        for (int j = i; j < s.size(); j++)
        {
            if (strs.find(s.substr(i, j - i + 1)) == strs.end())
            {
                strs.insert(s.substr(i, j - i + 1));
                ans = max(ans, maxUniqueSplit(s, j + 1, strs));
                strs.erase(s.substr(i, j - i + 1));
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.maxUniqueSplit("ababccc");
    return 0;
}