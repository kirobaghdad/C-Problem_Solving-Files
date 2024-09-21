#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> t(n + 1);

        t[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            t[i] = t[i / 2] + i % 2;
        }

        return t;
    }
};

int main()
{
    Solution s;
    s.countBits(5);

    return 0;
}