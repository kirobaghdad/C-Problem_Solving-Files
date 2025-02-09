#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        long long ans = ((nums.size() - 1) * nums.size()) / 2;

        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            m[i - nums[i]]++;

            ans -= (m[i - nums[i]] - 1);
        }

        return ans;
    }
};

int main()
{

    return 0;
}