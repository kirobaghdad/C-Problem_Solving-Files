#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int getGreatestPow(int x)
    {
        float a = (log(x) + 0.0);
        float b = (log(3) + 0.0);
        float temp = a / b;
        return temp;
    }

public:
    bool checkPowersOfThree(int n)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int prev = -1;
        int temp;

        while (n > 0)
        {
            temp = getGreatestPow(n);
            if (temp == prev)
                return false;
            prev = temp;

            n -= pow(3, temp);
        }

        return n == 0;
    }
};

int main()
{
    Solution s;

    cout << s.checkPowersOfThree(6574365);

    return 0;
}