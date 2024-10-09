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
        vector<int> a(nums.size(), 1);

        int suffix = 1;
        a[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            a[i] = a[i - 1] * nums[i];
        }

        for (int i = nums.size() - 1; i >= 1; i--)
        {
            a[i] = suffix * a[i - 1];
            suffix *= nums[i];
        }

        a[0] = suffix;

        return a;
    }
};

int main()
{
    Solution s;

    s.productExceptSelf({1, 2, 3, 4});

    return 0;
}