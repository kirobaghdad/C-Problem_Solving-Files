#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int mod = 1e9 + 7;
    
    long long pow_ll(long long base, long long exponent)
    {

        long long result = 1;
        while (exponent > 0)
        {
            if (exponent & 1)
            {
                result *= base;
                result %= mod;
            }
            if (exponent > 1)
            {
                base *= base;
                base %= mod;
            }
            exponent >>= 1;
        }
        return result;
    }

public:
    int countGoodNumbers(long long n)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        long long even = ceil(n / 2.0);
        long long odd = n - even;

        even = ((long long)pow_ll(5, even)) % mod;

        return (even * ((long long)pow_ll(4, odd) % mod)) % mod;
    }
};

int main()
{
    Solution s;

    cout << s.countGoodNumbers(50);

    return 0;
}
