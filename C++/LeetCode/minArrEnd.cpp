#include <iostream>
#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;

#define BMI2 __attribute__((__target__("bmi2")))
class Solution
{
public:
    long long minEnd(const int n, const int x) BMI2
    {
        return x | _pdep_u64(n - 1u, ~uint64_t(x));
    }
};

int main()
{
    Solution s;

    cout << s.minEnd(3, 4);

    return 0;
}