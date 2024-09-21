#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int solve(const vector<int> &days, const vector<int> &costs, int i = 0, int alreadyPaid = 0)
//     {
//         if (i == days.size())
//             return 0;

//         if (alreadyPaid >= days[i])
//             return solve(days, costs, i + 1, alreadyPaid);

//         int a = costs[0] + solve(days, costs, i + 1, days[i]);
//         int b = costs[1] + solve(days, costs, i + 1, days[i] + 6);
//         int c = costs[2] + solve(days, costs, i + 1, days[i] + 29);

//         return min(a, min(b, c));
//     }

//     int mincostTickets(vector<int> days, vector<int> costs)
//     {

//         return solve(days, costs);
//     }
// };

class Solution
{
public:
    vector<vector<int>> dp;
    int solve(const vector<int> &days, const vector<int> &costs, int i = 0, int alreadyPaid = 0)
    {

        if (dp[i][alreadyPaid] != -1)
        {
            return dp[i][alreadyPaid];
        }

        if (i == days.size())
            return 0;

        if (alreadyPaid >= days[i])
            return dp[i][alreadyPaid] = solve(days, costs, i + 1, alreadyPaid);

        int a = costs[0] + solve(days, costs, i + 1, days[i]);
        int b = costs[1] + solve(days, costs, i + 1, days[i] + 6);
        int c = costs[2] + solve(days, costs, i + 1, days[i] + 29);

        return dp[i][alreadyPaid] = min(a, min(b, c));
    }

    int mincostTickets(vector<int> days, vector<int> costs)
    {
        dp = vector<vector<int>>(days.size() + 1, vector<int>(365 + 30, -1));

        return solve(days, costs);
    }
};

int main()
{
    Solution s;

    cout << s.mincostTickets({1, 4, 6, 7, 8, 20}, {2, 7, 15});

    return 0;
}