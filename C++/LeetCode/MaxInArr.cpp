#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        vector<int> nums(n + 1);
        nums[0] = 0;
        int max = 0;

        if (n > 0)
        {
            nums[1] = 1;

            max = 1;
        }

        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                nums[i] = nums[i / 2];
            }
            else
            {
                nums[i] = nums[i / 2] + nums[i / 2 + 1];
            }

            if (nums[i] > max)
                max = nums[i];
        }

        return max;
    }
};

int main()
{
    Solution s;

    cout << s.getMaximumGenerated(7);

    return 0;
}