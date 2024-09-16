#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long ans = 0;

        int j = s.length();

        while (s[j - 1] == '1')
            j--;

        for (int i = 0; i < j; i++)
        {
            if (s[i] == '1')
            {
                ans += j - i - 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.minimumSteps("0111");

    return 0;
}