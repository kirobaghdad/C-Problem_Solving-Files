#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(nums.rbegin(), nums.rend());

        if (nums[nums.size() - 1] < k)
        {
            return -1;
        }

        int ans = 0;

        int i;

        for (i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
                ans++;
        }

        if (nums[i - 1] > k)
            ans++;

        return ans;
    }
};

int main()
{

    return 0;
}