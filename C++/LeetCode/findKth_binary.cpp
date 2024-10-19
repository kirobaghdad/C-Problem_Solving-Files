#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseInvert(string s)
    {
        for (int i = 0; i < s.size(); i++)
            s[i] = s[i] == '1' ? '0' : '1';

        reverse(s.begin(), s.end());

        return s;
    }

    char findKthBit(int n, int k, string s = "0")
    {
        if (k <= s.size())
        {
            return s[k - 1];
        }

        return findKthBit(n, k, s + '1' + reverseInvert(s));
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution s;

    cout << s.findKthBit(4, 11);

    return 0;
}