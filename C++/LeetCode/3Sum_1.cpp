#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        map<int, int> m;

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        int n;
        int sum = 0;

        for (auto it = m.begin(); it != m.end(); it++)
        {

            sum = it->first;

            it->second--;

            auto it0 = it;

            while (it0 != m.end())
            {
                if (it0->second)
                {
                    sum += it0->first;
                    it0->second--;

                    if (m.count(0 - sum) && 0 - sum >= it0->first)
                    {

                        if (m[0 - sum] > 0)
                            ans.push_back({it->first, it0->first, 0 - sum});
                    }

                    sum -= it0->first;

                    it0->second++;
                }

                it0++;
            }

            it->second++;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    s.threeSum({-1, 0, 1, 2, 0, -4, 0});

    return 0;
}