#include <iostream>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution
{
public:
    // turn = 0 -> first, turn = 1 ->second
    bool solve(const vector<int> &nums, int begin = 0, int end = INT_MAX, bool turn = 0, int sum0 = 0, int sum1 = 0)
    {
        if (end == INT_MAX)
            end = nums.size() - 1;

        if (begin > end)
        {
            return sum0 >= sum1;
        }

        if (turn == 0)
            return solve(nums, begin + 1, end, !turn, sum0 + nums[begin], sum1) || solve(nums, begin, end - 1, !turn, sum1 + nums[end], sum1);
        else
        {
            return solve(nums, begin + 1, end, !turn, sum0, sum1 + nums[begin]) || solve(nums, begin, end - 1, !turn, sum0, sum1 + nums[end]);
        }
    }

    bool predictTheWinner(vector<int> nums)
    {
        int n = solve(nums);

        return n >= accumulate(nums.begin(), nums.end(), 0) - n;
    }
};

int main()
{
    Solution s;

    cout << s.predictTheWinner({2, 4, 55, 6, 8});
    return 0;
}