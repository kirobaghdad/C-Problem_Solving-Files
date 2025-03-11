#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 0;

        map<char, int> c;

        int i = 0;

        for (int j = 0; j < s.size(); j++)
        {
            c[s[j]]++;

            while (c.size() == 3)
            {
                ans += s.size() - j;

                c[s[i]]--;

                if (!c[s[i]])
                {
                    c.erase(s[i]);
                }

                i++;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}