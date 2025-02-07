#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> queries)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_map<int, int> m1, m2;

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++)
        {
            if (m1.find(queries[i][0]) != m1.end())
            {
                m2[m1[queries[i][0]]]--;
                if (m2[m1[queries[i][0]]] == 0)
                    m2.erase(m1[queries[i][0]]);
            }

            m1[queries[i][0]] = queries[i][1];
            m2[queries[i][1]]++;

            ans.push_back(m2.size());
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> ans = s.queryResults(4, {{1, 4}, {2, 5}, {1, 3}, {3, 4}});

    return 0;
}