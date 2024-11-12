#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> items, vector<int> queries)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        // preprocessing

        map<int, int> m;

        for (int i = 0; i < items.size(); i++)
        {
            if (m.count(items[i][0]))
            {
                if (items[i][1] > m[items[i][0]])
                    m[items[i][0]] = items[i][1];
            }
            else
                m[items[i][0]] = items[i][1];
        }

        auto it = m.begin();
        auto it2 = m.begin();

        advance(it, 1);

        while (it != m.end())
        {
            if (it->second < it2->second)
                it->second = it2->second;

            advance(it, 1);
            advance(it2, 1);
        }

        vector<int> ans(queries.size(), 0);

        for (int i = 0; i < queries.size(); i++)
        {
            it = m.lower_bound(queries[i]);

            if (it->first == queries[i])
                ans[i] = it->second;
            else if (it != m.begin())
            {
                it--;
                ans[i] = (it)->second;
            }
        }

        return ans;
    }
};
int main()
{
    Solution s;

    s.maximumBeauty({{193, 732}, {781, 962}, {864, 954}, {749, 627}, {136, 746}, {478, 548}, {640, 908}, {210, 799}, {567, 715}, {914, 388}, {487, 853}, {533, 554}, {247, 919}, {958, 150}, {193, 523}, {176, 656}, {395, 469}, {763, 821}, {542, 946}, {701, 676}}, {885, 1445, 1580, 1309, 205, 1788, 1214, 1404, 572, 1170, 989, 265, 153, 151, 1479, 1180, 875, 276, 1584});

    return 0;
}