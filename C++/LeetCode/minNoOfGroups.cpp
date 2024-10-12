#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minGroups(vector<vector<int>> intervals)
    {
        vector<int> start_times, end_times;

        for (int i = 0; i < intervals.size(); i++)
        {
            start_times.push_back(intervals[i][0]);
            end_times.push_back(intervals[i][1]);
        }

        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int ans = 0, end_ptr = 0;

        for (auto start : start_times)
        {
            if (start > end_times[end_ptr])
                end_ptr++;
            else
                ans++;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.minGroups({{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}});

    return 0;
}