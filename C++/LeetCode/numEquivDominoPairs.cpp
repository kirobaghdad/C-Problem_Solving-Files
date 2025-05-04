#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct SetHash
{
    std::size_t operator()(const std::set<int> &s) const
    {
        std::size_t hash = 0;

        for (const int &val : s)
        {
            hash ^= std::hash<int>{}(val) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &domi)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_map<set<int>, int, SetHash> s;
        int ans = 0;
        set<int> temp;

        for (int i = 0; i < domi.size(); i++)
        {
            temp.clear();
            temp.insert(domi[i].begin(), domi[i].end());

            if (s.find(temp) != s.end())
            {
                ans += s[temp];
            }

            s[temp]++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}