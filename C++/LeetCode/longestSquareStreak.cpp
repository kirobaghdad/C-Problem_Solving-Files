#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSquareStreak(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(nums.begin(), nums.end());

        int sq;
        unordered_map<int, int> m;

        int ans = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            sq = sqrt(nums[i]);

            if (sq * sq == nums[i] && m.count(sq))
            {
                m[nums[i]] = m[sq] + 1;
                ans = max(ans, (int)m[nums[i]]);
            }
            else
            {
                m[nums[i]] = 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.longestSquareStreak({3, 13, 14, 14, 2});

    return 0;
}