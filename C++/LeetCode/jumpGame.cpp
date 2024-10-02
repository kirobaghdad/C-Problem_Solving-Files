#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int mReach = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i <= mReach)
            {
                if (nums[i] + i + 1 >= nums.size())
                    return true;

                mReach = max(mReach, i + nums[i]);
            }
            else
                return false;
        }

        return false;
    }
};

int main()
{

    return 0;
}