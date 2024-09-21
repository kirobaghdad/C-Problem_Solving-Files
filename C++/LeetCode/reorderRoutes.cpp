#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> connections)
    {

        vector<set<int>> adj(n);
        set<pair<int, int>> s;

        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][1]].insert(connections[i][0]);
            adj[connections[i][0]].insert(connections[i][1]);
            s.insert({connections[i][0], connections[i][1]});
        }

        queue<int> q;
        q.push(0);
        vector<bool> vis(n, 0);
        int temp;
        int ans = 0;

        while (q.size())
        {
            temp = q.front();
            q.pop();

            if (!vis[temp])
            {
                vis[temp] = true;

                for (auto it : adj[temp])
                {
                    q.push(it);

                    if (vis[it] == 0 && s.count({temp, it}))
                        ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.minReorder(6, {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}});

    return 0;
}