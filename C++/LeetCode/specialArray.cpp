#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialArray(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int ans = 0;

        int i = 0;

        sort(nums.begin(), nums.end());

        while (i < nums.size())
        {
            if (nums.size() - i == ans)
                return ans;

            while (i < nums.size() && ans == nums[i])
                i++;

            ans++;
        }

        return -1;
    }
};

int main()
{
    Solution s;

    cout << s.specialArray({0, 0});
    return 0;
}