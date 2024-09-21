#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> adjList(n);

        for (int i = 0; i < edges.size(); i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> isVisited(n, false);

        stack<int> s;
        s.push(source);

        bool ans = false;

        while (s.size())
        {
            int temp = s.top();
            s.pop();

            isVisited[temp] = true;

            if (temp == destination)
                return true;

            for (int i = 0; i < adjList[temp].size(); i++)
                if (!isVisited[adjList[temp][i]])
                    s.push(adjList[temp][i]);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};

    cout << s.validPath(6, edges, 0, 5);

    return 0;
}