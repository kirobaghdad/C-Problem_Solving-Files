#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> isVisited;
    vector<int> nodes;

    void solve(vector<vector<int>> &graph, int i)
    {
        if (isVisited[i] == false)
        {
            isVisited[i] = true;

            nodes.push_back(i);

            for (auto it : graph[i])
            {
                solve(graph, it);
            }
        }
    }

    bool checkComplete(vector<vector<int>> &graph)
    {
        bool ans = true;

        for (auto &it0 : nodes)
        {
            for (auto &it1 : nodes)
                if (it0 != it1 && find(graph[it0].begin(), graph[it0].end(), it1) == graph[it0].end())
                {
                    ans = false;
                    break;
                }
        }

        return ans;
    }

    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        isVisited = vector<bool>(n, false);
        int ans = 0;

        vector<vector<int>> graph(n);

        for (auto it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (isVisited[i] == false)
            {
                nodes.clear();

                solve(graph, i);

                if (checkComplete(graph))
                    ans++;
            }
        }

        return ans;
    }
};
int main()
{

    return 0;
}