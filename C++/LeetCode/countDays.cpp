#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        int ans = 0;

        int m = 0;

        for (auto &it : meetings)
        {
            if (it[0] > m)
            {
                ans += it[0] - m - 1;
            }

            m = max(m, it[1]);
        }

        return ans + days - m;
    }
};

int main()
{

    return 0;
}