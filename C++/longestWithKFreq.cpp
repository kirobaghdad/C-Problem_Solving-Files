#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> nums, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<int, int> m;

        int ans = INT_MIN;
        int j = 0;
        int i = 0;

        while (j < nums.size())
        {
            m[nums[j]]++;

            if (m[nums[j]] > k)
            {
                if (j - i > ans)
                    ans = j - i;

                while (i < nums.size() && nums[i] != nums[j])
                {
                    m[nums[i]]--;
                    i++;
                }

                m[nums[j]]--;

                i++;
            }

            j++;
        }

        if (j - i > ans)
            ans = j - i;

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.maxSubarrayLength({1, 2, 2, 1, 3}, 1);
    return 0;
}