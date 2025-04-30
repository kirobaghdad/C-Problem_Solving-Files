#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            float temp = log10(nums[i]);
            if (((int)floor(temp) + 1) % 2 == 0)
                ans++;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.findNumbers({100000});

    return 0;
}