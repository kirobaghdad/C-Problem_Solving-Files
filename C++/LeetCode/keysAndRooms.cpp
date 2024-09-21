#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        queue<int> q;
        q.push(0);
        vector<bool> vis(rooms.size(), false);
        int temp;

        while (q.size())
        {
            temp = q.front();
            q.pop();

            if (!vis[temp])
            {
                vis[temp] = 1;

                for (int i = 0; i < rooms[temp].size(); i++)
                {
                    if (!vis[rooms[temp][i]])
                        q.push(rooms[temp][i]);
                }
            }
        }

        for (int i = 0; i < vis.size(); i++)
            if (!vis[i])
                return false;

        return true;
    }
};

int main()
{

    return 0;
}