#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int ans = 0;

        sort(nums.begin(), nums.end());

        map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                m[nums[j] * nums[i]]++;

                ans += 8 * (m[nums[j] * nums[i]] - 1);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.tupleSameProduct({20, 10, 6, 24, 15, 5, 4, 30});
    return 0;
}