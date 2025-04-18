#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string ans;

    void solve(int n, int i = 2)
    {
        if (i >= n + 1)
            return;

        string temp;

        for (int i = 0; i < ans.size();)
        {
            int s = 1;
            int x = ans[i];
            i++;

            while (i < ans.size() && ans[i] == x)
            {
                s++;
                i++;
            }

            temp += s + '0';
            temp += x;
        }

        ans = temp;

        solve(n, i + 1);
    }

    string countAndSay(int n)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        ans = '1';

        solve(n);

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.countAndSay(4);
    return 0;
}