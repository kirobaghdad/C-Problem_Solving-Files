#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfsRec(vector<vector<int>> &isConnected, vector<bool> &isVisited, int i)
    {
        isVisited[i] = true;

        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isVisited[j] == false && isConnected[i][j])
                dfsRec(isConnected, isVisited, j);
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int count = 0;
        vector<bool> isVisited(isConnected.size(), false);

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (isVisited[i] == false)
            {
                count++;
                dfsRec(isConnected, isVisited, i);
            }
        }

        return count;
    }
};