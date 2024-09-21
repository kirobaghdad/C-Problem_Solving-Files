#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int c = 0;
        int ans = 0;
        int i = 0;

        for (; i < s.size(); i++)
        {
            if (s[i] == '(')
                c++;
            else if (s[i] == ')')
            {
                if (c == 0)
                {
                    s.erase(i, 1);
                    i--;
                    ans++;
                }
                else
                    c--;
            }
        }

        i = s.size() - 1;

        while (c)
        {
            if (s[i] == '(')
            {
                s.erase(i, 1);
                c--;
            }
            i--;
        }

        return s;
    }
};
int main()
{
    Solution s;
    cout << s.minRemoveToMakeValid("))((");
    return 0;
}