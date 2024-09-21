#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> nums, int goal)
    {
        unordered_map<int, int> m;
        m[0] = 1;

        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (m.count(sum - goal))
                count += m[sum - goal];

            m[sum]++;
        }

        return count;
    }
};

int main()
{
    Solution s;
    cout << s.numSubarraysWithSum({1, 0, 1, 0, 1}, 1);
    return 0;
}