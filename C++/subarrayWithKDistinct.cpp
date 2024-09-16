#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> nums, int k)
    {

        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<int, int> m;

        int ans = 0;
        int j = 0;
        int i = 0;

        while (j < nums.size())
        {
            m[nums[j]]++;

            while (m.size() > k)
            {
                m[nums[i]]--;

                if (m[nums[i]] == 0)
                    m.erase(nums[i]);

                i++;
            }

            ans += j - i + 1;

            j++;
        }

        m.clear();

        j = 0;
        i = 0;

        while (j < nums.size())
        {
            m[nums[j]]++;

            while (m.size() > k - 1)
            {
                m[nums[i]]--;

                if (m[nums[i]] == 0)
                    m.erase(nums[i]);

                i++;
            }

            ans -= j - i + 1;
            j++;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.subarraysWithKDistinct({1, 2, 1, 2, 3}, 2);

    return 0;
}