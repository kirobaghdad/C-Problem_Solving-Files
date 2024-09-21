#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> g, vector<int> s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;

        int ans = 0;

        for (i = 0; i < g.size() && j < s.size(); i++)
        {
            if (s[j] >= g[i])
            {
                ans++;
            }
            else
                i--;
            j++;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.findContentChildren({1, 2, 3}, {1, 1, 5});
    return 0;
}