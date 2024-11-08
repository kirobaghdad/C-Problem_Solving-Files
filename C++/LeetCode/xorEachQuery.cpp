#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> ans(nums.size(), 0);

        int temp = 0;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            temp = temp ^ nums[nums.size() - i - 1];

            ans[i] = pow(2, maximumBit) - temp - 1;
        }

        return ans;
    }
};
int main()
{

    return 0;
}