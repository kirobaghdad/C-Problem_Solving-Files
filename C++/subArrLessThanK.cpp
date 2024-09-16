#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> nums, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int ans = 0;
        int n = nums.size();
        int product = 1;

        int j = 0;

        for (int i = 0; i < n; i++)
        {
            if (j < i)
                j = i;

            while (j < n)
            {
                product *= nums[j];

                if (product < k)
                    ans += j - i + 1;

                else
                {
                    product /= nums[j];
                    break;
                }

                j++;
            }

            if (j == n)
                return ans;

            if (i != j)
                product /= nums[i];
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.numSubarrayProductLessThanK({10, 5, 2, 6}, 100);

    return 0;
}