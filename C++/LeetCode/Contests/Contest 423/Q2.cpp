#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIncreasingSubarrays(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int ans = 1;

        vector<int> incs;

        incs.push_back(-1);

        for (int i = 1; i <= nums.size(); i++)
        {
            if (i == nums.size() || nums[i] <= nums[i - 1])
            {
                incs.push_back(i - 1);
            }
        }

        for (int i = 1; i < incs.size(); i++)
        {
            ans = max(ans, (incs[i] - incs[i - 1]) / 2);

            if (i != 1)
            {
                ans = max(ans, min(incs[i] - incs[i - 1], incs[i - 1] - incs[i - 2]));
            }
        }

        return ans;
    }
};

int main()
{

    Solution s;

    cout << s.maxIncreasingSubarrays({-1, 0, 1, 2, 3, 0, 1, 2});

    return 0;
}
