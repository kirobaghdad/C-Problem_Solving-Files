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

        stack<int> stk;

        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i];
            if (c == '(')
            {
                stk.push(i);
            }
            else if (c == ')')
            {
                if (!stk.empty())
                {
                    stk.pop();
                }
                else
                {
                    s[i] = '*';
                }
            }
        }

        string ans = "";
        while (!stk.empty())
        {
            s[stk.top()] = '*';
            stk.pop();
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '*')
            {
                ans += s[i];
            }
        }

        return ans;
    }
};
int main()
{

    Solution s;
    cout << s.minRemoveToMakeValid("))((");
    return 0;
}