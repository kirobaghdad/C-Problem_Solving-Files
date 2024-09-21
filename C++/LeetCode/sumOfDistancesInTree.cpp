#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class GraphNode
{
public:
    int data;
    vector<int> children;

    GraphNode(int data)
    {
        this->data = data;
    }

    void addChild(int child)
    {
        children.push_back(child);
    }
};

class Solution
{
public:
    vector<vector<int>> dp;
    vector<bool> isVisited;

    int findDist(vector<GraphNode> &nodes, int start)
    {
        isVisited[start] = true;

        int temp = 0;

        for (int i = 0; i < nodes[start].children.size(); i++)
        {
            dp[start][nodes[start].children[i]] = 1 + findDist(nodes, nodes[start].children[i]);
        }

        return
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<GraphNode> nodes;

        for (int i = 0; i < n; i++)
            nodes.push_back(GraphNode(i));

        for (int i = 0; i < edges.size(); i++)
        {
            nodes[edges[i][0]].addChild(edges[i][1]);
            nodes[edges[i][1]].addChild(edges[i][0]);
        }

        dp = vector<vector<int>>(nodes.size(), vector<int>(nodes.size(), 0));

        int ans = 0;

        for (int i = 0; i < nodes.size(); i++)
        {
            isVisited = vector<bool>(n, 0);
            ans += findDist(nodes, i);
        }
    }
};

int main()
{

    return 0;
}