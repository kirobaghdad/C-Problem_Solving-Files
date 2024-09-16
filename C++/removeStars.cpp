#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int j = 0;

        for (int i = 0; i < s.size(); i++)
        {
            j = i;
            bool f = 0;
            while (s[j] == '*')
            {
                j++;
                f = 1;
            }

            s.erase(i - (j - i), 2 * (j - i));

            i = j - 2 * (j - i);

            if (f)
                i--;
        }

        return s;
    }
};

int main()
{
    Solution s;

    cout << s.removeStars("leet**cod*e");

    return 0;
}