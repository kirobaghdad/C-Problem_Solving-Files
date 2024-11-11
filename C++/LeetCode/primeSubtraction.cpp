#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> primes;

    void calcSieveOfEratosthenes()
    {

        primes[1] = 1;

        for (int i = 2; i <= 1000; i++)
        {
            if (primes[i] == false)
            {
                int j = i * i;

                if (j > 1000)
                    break;

                for (; j <= 1000; j = j + i)
                {
                    primes[j] = 1;
                }
            }
        }
    }

    bool primeSubOperation(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        primes = vector<bool>(1000, 0);
        calcSieveOfEratosthenes();

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] >= nums[i + 1])
            {
                int x = nums[i] - nums[i + 1] + 1;

                while (x <= 1000 && x <= nums[i] && primes[x] == 1)
                {
                    x++;
                }

                if (x == 1000 || x >= nums[i])
                    return false;

                nums[i] -= x;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;

    cout << s.primeSubOperation({5, 8, 3});
    return 0;
}