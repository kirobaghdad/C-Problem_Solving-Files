#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<string> isVis;
    bool found;

    void getAns(map<string, map<string, double>> &m, double &ans, string currNode, string req)
    {
        isVis.insert(currNode);

        if (currNode == req)
        {
            found = true;
            return;
        }

        for (auto it : m[currNode])
        {
            if (!isVis.count(it.first))
            {
                ans = ans * it.second;
                getAns(m, ans, it.first, req);
                if (found)
                    break;
                ans = ans / it.second;
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>> equations, vector<double> values, vector<vector<string>> queries)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        map<string, map<string, double>> m;
        int i = 0;

        for (auto it : equations)
        {
            m[it[0]][it[1]] = values[i];
            m[it[1]][it[0]] = 1.0 / values[i];
            i++;
        }

        vector<double> ans(queries.size());
        double a = 1;

        for (i = 0; i < queries.size(); i++)
        {
            if (m.count(queries[i][0]) == 0 || m.count(queries[i][1]) == 0)
                ans[i] = -1;
            else if (queries[i][0] == queries[i][1])
                ans[i] = 1;
            else if (m.count(queries[i][0]) && m[queries[i][0]].count(queries[i][1]))
                ans[i] = m[queries[i][0]][queries[i][1]];
            else
            {
                isVis.clear();
                found = false;
                a = 1;
                getAns(m, a, queries[i][0], queries[i][1]);

                if (found == false)
                    ans[i] = -1;
                else
                    ans[i] = a;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<double> ans = s.calcEquation({{"a", "b"}, {"b", "c"}}, {2.0, 3.0}, {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}});

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}