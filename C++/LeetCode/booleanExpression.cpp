#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool parseBoolExpr(string ex)
    {
        int i = 0, j = 0;
        int c = 0;

        bool ans;

        if (ex[i] == '|' || ex[i] == '&')
        {
            i += 2;
            j = i;

            c = 1;

            ans = ex[0] != '|';

            while (i < ex.size() && c)
            {
                while (!(c == 1 && ex[j] == ',') && c)
                {
                    if (ex[j] == ')')
                        c--;
                    else if (ex[j] == '(')
                        c++;

                    j++;
                }

                if (!c)
                    j--;

                if (ex[0] == '|')
                    ans = ans | parseBoolExpr(ex.substr(i, j - i));
                else
                    ans = ans & parseBoolExpr(ex.substr(i, j - i));

                i = ++j;
            }
        }
        else if (ex[i] == '!')
        {
            i += 2;

            ans = !parseBoolExpr(ex.substr(i, ex.size() - i));
        }
        else if (ex[i] == 't')
        {
            return true;
        }
        else
            return false;

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.parseBoolExpr("|(&(t,f,t),!(t))");

    return 0;
}