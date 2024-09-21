#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalMoney(int n)
    {

        int ans = 0;

        int w = n / 7;

        int temp = 0;

        for (int i = 1; i < w; i++)
        {
            temp += i * 7;
        }

        ans += 28 * w + temp;

        temp = n % 7;
        ans += (((temp) * (temp + 1)) / 2) + temp * (w);

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.totalMoney(4);

    return 0;
}