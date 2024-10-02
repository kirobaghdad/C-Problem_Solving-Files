#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        k = k % nums.size();
        vector<int> temp = vector<int>(nums.end() - k, nums.end());

        for (int i = nums.size() - k - 1; i >= 0; i--)
        {
            nums[i + k] = nums[i];
        }

        for (int i = 0; i < k; i++)
        {
            nums[i] = temp[i];
        }
    }
};

int main()
{

    return 0;
}