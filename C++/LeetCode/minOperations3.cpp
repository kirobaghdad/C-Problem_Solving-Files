#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (i + 2 < nums.size())
                {
                    nums[i] = !nums[i];
                    nums[i + 1] = !nums[i + 1];
                    nums[i + 2] = !nums[i + 2];
                }
                else
                {
                    return -1;
                }

                ans++;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}