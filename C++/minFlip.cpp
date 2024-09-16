#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int prevZeros = 0;
        int ind = -1;
        int ones = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (ind == -1)
            {
                if (s[i] == '1')
                {
                    ind = i;
                    ones++;
                }
                else
                {
                    prevZeros++;
                }
            }
            else
            {
                if (s[i] == '1')
                    ones++;
            }
        }

        return ones > s.size() - ind - ones ? s.size() - ind - ones : ones;
    }
};

int main()
{
    Solution s;
    cout << s.minFlipsMonoIncr("00110");

    return 0;
}