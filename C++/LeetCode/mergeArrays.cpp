#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<vector<int>> ans;
        map<int, int> id;
        int i = 0;

        for (auto &it : nums1)
        {
            ans.push_back(it);
            id.insert({it[0], i});
            i++;
        }

        for (auto &it : nums2)
        {
            if (id.find(it[0]) == id.end())
            {
                ans.push_back(it);
            }
            else
            {
                ans[id[it[0]]][1] += it[1];
            }
        }

        sort(ans.begin(), ans.end(), compare);

        return ans;
    }
};

int main()
{

    return 0;
}