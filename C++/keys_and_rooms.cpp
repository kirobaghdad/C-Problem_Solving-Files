#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int currKey;
        set<int> keys({1});
        // set<int> visited;

        while (true)
        {
            currKey = *keys.rbegin();

            if (currKey <= 0)
                break;

            for (int i = 0; i < rooms[currKey - 1].size(); i++)
            {
                if (keys.find(-(rooms[currKey - 1][i] + 1)) == keys.end())
                    keys.insert(rooms[currKey - 1][i] + 1);
            }

            keys.erase(currKey);
            keys.insert(-1 * currKey);
        }

        return keys.size() == rooms.size();
    }
};
