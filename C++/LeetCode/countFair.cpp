#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long BS(map<int, int> &m, int low, int up)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        auto it = m.lower_bound(low);

        if (it->first > up)
            return 0;

        auto it1 = m.lower_bound(up);

        if (it1->first != up && it1 == m.begin())
            return 0;

        if (it1->first != up)
            it1--;

        long long ans = it1->second - it->second + 1;

        return ans;
    }

    long long countFairPairs(vector<int> nums, int lower, int upper)
    {
        long long ans = 0;

        sort(nums.begin(), nums.end());

        map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = i;

            i++;

            while (i < nums.size() && nums[i] == nums[i - 1])
                i++;

            i--;
        }

        long long temp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > lower - nums[i] && nums[i] > upper - nums[i])
                break;

            temp = BS(m, lower - nums[i], upper - nums[i]);

            if (!temp)
                break;

            ans += temp;
        }

        return ans;
    }
};
int main()
{
    Solution s;

    cout << s.countFairPairs({1, 7, 9, 2, 5}, 11, 11);

    return 0;
}