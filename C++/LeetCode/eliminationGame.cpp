#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int start, int end, int d = 2, bool dir = 0)
    {
        if (start == end)
            return start;

        if (!dir)
        {
            int t = start + d / 2;

            while (t <= end)
                t += d;

            t -= d;

            return solve(start + d / 2, t, d * 2, !dir);

            // return solve(start + d / 2, (end / d) * d, d * 2, !dir);
            // int t1 = start + d / 2;
            // int t2 = end;
            // nums.clear();

            // for (int i = t1; i <= t2; i += d)
            // {
            //     nums.push_back(i);
            // }
        }
        else
        {
            int t = end - d / 2;

            while (t >= start)
                t -= d;

            t += d;

            return solve(t, end - d / 2, d * 2, !dir);
            // int t1 = nums[nums.size() - 2];
            // int t2 = nums[0];
            // nums.clear();

            // for (int i = t1; i >= t2; i -= d)
            // {
            //     nums.push_back(i);
            // }

            // reverse(nums.begin(), nums.end());
        }

        // return solve(nums, d * 2, !dir);
    }

    int lastRemaining(int n)
    {

        return solve(1, n);
    }
};

int main()
{
    Solution s;
    cout << s.lastRemaining(100000000);

    return 0;
}