#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> grid)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = grid.size() * grid.size();
        int sum = (n * (n + 1)) / 2;
        long long sum_of_squares = ((long long)n * (n + 1) * (2 * n + 1)) / 6;

        int act_sum = 0;
        long long act_sum_of_squares = 0;

        for (auto &it : grid)
        {
            for (auto &ele : it)
            {
                act_sum += ele;
                act_sum_of_squares += ele * ele;
            }
        }

        // b - a
        int diff_b_a = sum - act_sum;

        int sum_a_b = (sum_of_squares - act_sum_of_squares) / diff_b_a;

        return {(sum_a_b - diff_b_a) / 2, (diff_b_a + sum_a_b) / 2};
    }
};

int main()
{
    Solution s;

    vector<int> ans = s.findMissingAndRepeatedValues({{1, 3}, {2, 2}});

    return 0;
}