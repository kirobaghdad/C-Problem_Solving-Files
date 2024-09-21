#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int back = 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '#')
            {
                back++;
                s.erase(s.begin() + i);
            }
            else
            {
                if (back != 0)
                {
                    s.erase(s.begin() + i);
                    back--;
                }
            }
        }

        back = 0;

        for (int i = t.size() - 1; i >= 0; i--)
        {
            if (t[i] == '#')
            {
                back++;
                t.erase(t.begin() + i);
            }
            else
            {
                if (back != 0)
                {
                    t.erase(t.begin() + i);
                    back--;
                }
            }
        }

        return s == t;
    }
};

int main()
{

    Solution s;
    cout << s.backspaceCompare("a#c", "b");

    return 0;
}