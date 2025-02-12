#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, pair<int, int>> m;
        int temp0 = 0;
        int temp1;

        for (int i = 0; i < nums.size(); i++)
        {
            temp0 = 0;
            temp1 = nums[i];

            while (temp1)
            {
                temp0 += temp1 % 10;
                temp1 /= 10;
            }

            if (m[temp0].first > m[temp0].second)
            {
                if (nums[i] > m[temp0].second)
                {
                    m[temp0].second = nums[i];
                }
            }
            else
            {
                if (nums[i] > m[temp0].first)
                {
                    m[temp0].first = nums[i];
                }
            }
        }

        int ans = -1;

        for (auto &it : m)
        {
            if (it.second.first && it.second.second)
            {
                ans = max(ans, it.second.first + it.second.second);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}