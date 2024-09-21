#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> visited;
    vector<int> dist;
    vector<int> pred;

    int dijkstra(vector<vector<int>> &adj, int dest)
    {
        queue<int> q;
        q.push(0);
        visited[0] = true;
        pred[0] = -1;

        while (!q.empty())
        {
            int v = q.front();
            q.pop();

            for (int u : adj[v])
            {
                if (!visited[u])
                {
                    visited[u] = true;
                    q.push(u);
                    dist[u] = dist[v] + 1;
                    pred[u] = v;

                    if (u == dest)
                        return true;
                }
            }
        }

        return false;
    }

    int openLock(vector<string> &deadends, string target)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<vector<int>> nums(10000, vector<int>());

        visited = vector<bool>(10000, false);

        dist = vector<int>(10000, 0);
        pred = vector<int>(10000, -1);

        for (int i = 0; i < 10000; i++)
        {
            string t = to_string(i);
            t = string(4 - t.length(), '0') + t;

            for (int j = 0; j < 4; j++)
            {
                string t0 = (t[j] == '0' ? t.substr(0, j) + '9' + t.substr(j + 1, 4 - j - 1) : t.substr(0, j) + to_string((t[j] - '0') - 1) + t.substr(j + 1, 4 - j - 1));
                string t1 = (t[j] == '9' ? t.substr(0, j) + '0' + t.substr(j + 1, 4 - j - 1) : t.substr(0, j) + to_string((t[j] - '0') + 1) + t.substr(j + 1, 4 - j - 1));

                if ((find(deadends.begin(), deadends.end(), t0) == deadends.end()) && (find(deadends.begin(), deadends.end(), t1) == deadends.end()) && (find(deadends.begin(), deadends.end(), t) == deadends.end()))
                {

                    nums[i].push_back(stoi(t0));
                    nums[i].push_back(stoi(t1));
                }
            }
        }

        if (!dijkstra(nums, stoi(target)))
            return -1;

        vector<int> path;
        for (int v = stoi(target); v != -1; v = pred[v])
            path.push_back(v);

        return path.size() - 1;
    }
};

int main()
{
    Solution s;

    cout << s.openLock({"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"}, "8888");

    return 0;
}