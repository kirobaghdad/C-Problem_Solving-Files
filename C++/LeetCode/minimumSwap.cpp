#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int xyPattern = 0, yxPattern = 0;

        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i] && s1[i] == 'x')
                xyPattern++;
            else if (s1[i] != s2[i] && s1[i] == 'y')
                yxPattern++;
        }

        return (xyPattern % 2) == (yxPattern % 2) ? xyPattern / 2 + yxPattern / 2 + (xyPattern % 2) + yxPattern % 2 : -1;
    }
};

int main()
{
    Solution s;
    cout << s.minimumSwap("xx", "yy");

    return 0;
}