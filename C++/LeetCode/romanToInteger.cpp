#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getRoman(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }

        return 0;
    }

    int romanToInt(string s)
    {
        int last = INT_MAX;

        int ans = 0;
        int temp;

        for (int i = 0; i < s.size(); i++)
        {

            if (getRoman(s[i]) > last)
            {
                ans -= 2 * last;
            }

            last = getRoman(s[i]);
            ans += last;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.romanToInt("LVIII");

    return 0;
}