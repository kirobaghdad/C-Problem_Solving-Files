#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> closestPrimes(int left, int right)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = max(left, right);
        vector<bool> primes(n + 1, true);
        primes[0] = false;
        primes[1] = false;

        // Sieve of Eratosthenes
        for (int p = 2; p * p <= n; p++)
        {
            if (primes[p])
            {
                for (int i = p * p; i <= n; i += p)
                    primes[i] = false;
            }
        }

        int a = -1;
        int b = -1;

        int prev = -1;

        for (int i = left; i <= right; i++)
        {
            if (primes[i])
            {
                if (prev != -1)
                {
                    if (b == -1 || (i - prev < b - a))
                    {
                        a = prev;
                        b = i;
                    }
                }

                prev = i;
            }
        }

        return {a, b};
    }
};

int main()
{
    Solution s;

    vector<int> ans = s.closestPrimes(10, 19);
    return 0;
}