#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int ans = 0;

        for (int i = columnTitle.length() - 1; i >= 0; i--)
        {
            ans += (columnTitle[i] - 'A' + 1) * pow(26, columnTitle.length() - i - 1);
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.titleToNumber("ZY");

    return 0;
}