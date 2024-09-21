#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long nCr(int n, int r)
    {
        return fact(n) / (fact(r) * fact(n - r));
    }

    // Returns factorial of n
    long fact(int n)
    {
        if (n == 0)
            return 1;
        long res = 1;
        for (int i = 2; i <= n; i++)
            res = res * i;
        return res;
    }

    int beautifulSubsets(vector<int> nums, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        map<int, int> m;

        int ans = nums.size();

        int l = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int n = m.size();

            if (m.count(nums[i] - k))
            {
                n--;
            }

            if (m.count(nums[i] + k))
            {
                n--;
            }

            for (int i = 1; i <= n; i++)
                ans += nCr(n, i);

            ans -= l ? l + 1 : l;
            l += m.size() - n;

            m[nums[i]]++;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.beautifulSubsets({2, 4, 6}, 2);
    return 0;
}