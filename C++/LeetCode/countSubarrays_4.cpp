#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 0;

        for (int i = 0; i + 2 < nums.size(); i += 1)
        {
            if ((nums[i] + nums[i + 2]) + 0.0 == nums[i + 1] / 2.0)
                ans++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}