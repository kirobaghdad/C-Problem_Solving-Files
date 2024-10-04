#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int near = 0, far = 0, jumps = 0;

        while (far < nums.size() - 1)
        {
            int farthest = 0;
            for (int i = near; i <= far; i++)
            {
                farthest = max(farthest, i + nums[i]);
            }
            near = far + 1;
            far = farthest;
            jumps++;
        }

        return jumps;
    }
};

int main()
{
    Solution s;

    cout << s.jump({2, 3, 0, 1, 4});
    return 0;
}