#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> nums)
    {
        vector<pair<int, int>> all;

        // Merge lists with list index
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int num : nums[i])
            {
                all.emplace_back(num, i);
            }
        }

        sort(all.begin(), all.end());

        unordered_map<int, int> count;
        int l = 0, r = 0;
        int totalLists = nums.size();
        int uniqueListsInWindow = 0;
        int minRange = INT_MAX;
        vector<int> result(2);

        while (r < all.size())
        {
            count[all[r].second]++;
            if (count[all[r].second] == 1)
                uniqueListsInWindow++;

            while (uniqueListsInWindow == totalLists)
            {
                int currentRange = all[r].first - all[l].first;
                if (currentRange < minRange)
                {
                    minRange = currentRange;
                    result = {all[l].first, all[r].first};
                }

                count[all[l].second]--;
                if (count[all[l].second] == 0)
                    uniqueListsInWindow--;
                l++;
            }

            r++;
        }

        return result;
    }
};

int main()
{
    Solution s;

    s.smallestRange({{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}});

    return 0;
}