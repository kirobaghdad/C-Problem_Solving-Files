#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();

        vector<int> a = vector<int>(n, 0);
        // vector<int> b = vector<int>(n, 0);

        a[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            a[i] = a[i - 1] * nums[i];
        }

        for (int j = n - 2; j >= 0; j--)
        {
            nums[j] = nums[j + 1] * nums[j];
        }

        nums[0] = nums[1];

        for (int i = 1; i < n - 1; i++)
        {
            nums[i] = a[i - 1] * nums[i + 1];
        }
        nums[n - 1] = a[n - 2];

        return nums;
    }
};
int main()
{
    Solution s;

    s.productExceptSelf({1, 2, 3, 4});

    return 0;
}