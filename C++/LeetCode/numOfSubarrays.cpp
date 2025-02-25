#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int odd = 0;
        int even = 1;

        vector<int> sum(arr.size() + 1, 0);

        for (int i = 0; i < arr.size(); i++)
        {
            sum[i + 1] = sum[i] + arr[i];
        }

        int ans = 0;
        const unsigned int M = 1000000007;

        for (int i = 1; i < sum.size(); i++)
        {
            if (sum[i] % 2)
            {
                // odd
                ans = (ans + even) % M;
                odd++;
            }
            else
            {
                // even
                ans = (ans + odd) % M;
                even++;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}