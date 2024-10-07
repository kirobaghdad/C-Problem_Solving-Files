#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> m;
        set<char> vals;

        for (int i = 0; i < s.size(); i++)
        {
            if (m.count(s[i]))
            {
                if (t[i] != m[s[i]])
                    return false;
            }
            else
            {
                if (vals.count(t[i]))
                    return false;

                m[s[i]] = t[i];
                vals.insert(t[i]);
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}