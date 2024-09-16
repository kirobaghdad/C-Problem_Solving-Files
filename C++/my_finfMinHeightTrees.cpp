#include <iostream>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    vector<vector<int>> adj;
    vector<int> degree;
    int V;

    Graph(int n)
    {
        V = n;
        degree = vector<int>(V, 0);
        adj = vector<vector<int>>(V);
    }

    void addEdge(int s, int e)
    {
        adj[s].push_back(e);
        adj[e].push_back(s);
        degree[s]++;
        degree[e]++;
    }

    vector<int> findMinHeights()
    {
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (degree[i] == 1)
                q.push(i);
        }

        while (V > 2)
        {
            int popEle = q.size();
            V -= popEle;

            for (int i = 0; i < popEle; i++)
            {
                int t = q.front();
                q.pop();

                for (auto j = adj[t].begin(); j != adj[t].end(); j++)
                {
                    degree[*j]--;
                    if (degree[*j] == 1)
                        q.push(*j);
                }
            }
        }

        vector<int> ans;
        int t = q.size();

        for (int i = 0; i < t; i++)
        {
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
        }

        return ans;
    }
};

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> edges)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        Graph g(n);

        for (int i = 0; i < edges.size(); i++)
        {
            g.addEdge(edges[i][0], edges[i][1]);
        }

        if (!edges.size())
        {
            vector<int> ans = vector<int>(n);
            iota(ans.begin(), ans.end(), 0);
            return ans;
        }

        return g.findMinHeights();
    }
};

int main()
{
    Solution s;

    vector<int> res = s.findMinHeightTrees(1, {});
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}