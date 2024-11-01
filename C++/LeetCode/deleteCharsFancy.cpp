#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            int j = i;

            while (j < s.size() && s[j] == c)
                j++;

            if (j - i >= 3)
            {
                s = s.substr(0, i + 2) + (j != s.size() ? s.substr(j) : "");

                j -= j - i - 2;
                i = j;
            }

            i = j - 1;
        }

        return s;
    }
};

int main()
{
    Solution s;

    cout << s.makeFancyString("abbcccddddeeeee");

    return 0;
}