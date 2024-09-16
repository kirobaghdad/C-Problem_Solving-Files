#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp;

    int solve(const vector<int> &primes, int n, int last = 1, int len = 1, int i = 0)
    {
        if (i == dp.size())
            return 0;

        if (len == n)
            return last;

        int prev, next;
        if (i == 0)
            prev = INT_MAX;
        else
            prev = dp[i - 1];

        if (i == dp.size() - 1)
            next = INT_MAX;
        else
            next = dp[i + 1];

        if (dp[i] < next && dp[i] < prev)
        {
            int temp = dp[i];
            dp[i] = dp[i] * *min_element(primes.begin(), primes.begin() + i);
            return solve(primes, n, temp, len + 1, i);
        }

        if (prev < next)
            return solve(primes, n, last, len, i - 1);

        if (prev > next)
            return solve(primes, n, last, len, i + 1);
    }

    int nthSuperUglyNumber(int n, vector<int> primes)
    {
        dp = primes;

        return solve(primes, n);
    }
};

int main()
{
    Solution s;
    cout << s.nthSuperUglyNumber(12, {2, 7, 13, 19});

    return 0;
}