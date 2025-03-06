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
        int sum_of_squares = (n * (n + 1) * (2 * n + 1)) / 6;

        int act_sum = 0;
        int act_sum_of_squares = 0;

        for (auto &it : grid)
        {
            for (auto &ele : it)
            {
                act_sum += ele;
                act_sum_of_squares += ele * ele;
            }
        }

        // a - b
        int diff_a_b = sum - act_sum;

        int sum_a_b = (sum_of_squares - act_sum_of_squares) / diff_a_b;

        return {(sum_a_b - diff_a_b) / 2, (diff_a_b + sum_a_b) / 2};
    }
};
int main()
{
    Solution s;

    s.findMissingAndRepeatedValues({{1, 3}, {2, 2}});

    return 0;
}