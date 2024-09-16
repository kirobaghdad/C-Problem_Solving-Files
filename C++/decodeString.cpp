#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(string &s, int i = 0)
    {

        if (i == s.size())
            return s;

        if (isdigit(s[i]))
        {
            string dig;

            int j = i;

            while (isdigit(s[i]))
            {
                dig += s[i];
                i++;
            }
            i += 1;

            string temp;
            int num = stoi(dig);

            int x = 1;

            while (x != 0)
            {
                if (s[i] == '[')
                    x++;
                else if (s[i] == ']')
                    x--;

                if (x != 0)
                {
                    temp += s[i];
                    i++;
                }
            }

            s.erase(j, temp.size() + 2 + dig.size());

            for (int k = 0; k < num; k++)
            {
                s.insert(j, temp);
                j += temp.size();
            }

            j -= temp.size() * num;

            return solve(s, j);
        }
        return solve(s, i + 1);
    }

    string decodeString(string s)
    {
        return solve(s);
    }
};

int main()
{
    Solution s;

    string t = "3[a2[c]]";

    cout << s.decodeString("100[leetcode]");

    return 0;
}