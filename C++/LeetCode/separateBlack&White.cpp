#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumSteps(string s)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        long long one = 0;

        long long ans = 0;

        int i = 0;
        long long zero;

        while (i < s.size())
        {
            if (s[i] == '0')
                i++;
            else
            {
                // one = 0;

                while (i < s.size() && s[i] == '1')
                {
                    one++;
                    i++;
                }

                zero = 0;

                while (i < s.size() && s[i] == '0')
                {
                    zero++;
                    i++;
                }

                ans += zero * one;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}