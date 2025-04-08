#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        set<int> n;

        int ans = 0;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (n.find(nums[i]) != n.end())
            {
                ans = ceil((i + 1) / 3.0);
                break;
            }

            n.insert(nums[i]);
        }

        return ans;
    }
};

int main()
{

    return 0;
}