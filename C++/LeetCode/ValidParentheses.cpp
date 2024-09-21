#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> par;
        bool ans = true;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                par.push(s[i]);
            else
            {
                if (par.size() == 0)
                {
                    ans = false;
                    break;
                }
                else if ((s[i] == ')' && par.top() == '(') || (s[i] == '}' && par.top() == '{') || (s[i] == ']' && par.top() == '['))
                    par.pop();
                else
                {
                    ans = false;
                    break;
                }
            }
        }

        if (par.size() != 0)
            ans = false;

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.isValid(")");

    return 0;
}