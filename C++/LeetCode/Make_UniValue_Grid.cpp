#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // lineraize
        vector<int> values;

        for (auto &it : grid)
        {
            for (auto &it0 : it)
                values.push_back(it0);
        }

        sort(values.begin(), values.end());

        for (int i = 0; i < values.size(); i++)
        {
            if (abs(values[i] - values[0]) % x != 0)
                return -1;
        }

        int median = values[values.size() / 2];
        int ans = 0;

        for (int i = 0; i < values.size(); i++)
        {
            ans += abs(values[i] - median) / x;
        }

        return ans;
    }
};

int main()
{

    return 0;
}