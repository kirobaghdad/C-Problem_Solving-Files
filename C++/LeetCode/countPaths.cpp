#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> roads)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<vector<pair<int, int>>> graph(n);

        for (auto &it : roads)
        {
            graph[it[0]].emplace_back(it[1], it[2]);
            graph[it[1]].emplace_back(it[0], it[2]);
        }

        vector<int> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);

        ways[0] = 1;
        dist[0] = 0;

        // min distance, node (DP)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);

        const int MOD = 1e9 + 7;

        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();

            if (temp.first > dist[temp.second])
                continue;

            for (auto &[neighbor, time] : graph[temp.second])
            {
                if (dist[temp.second] + time < dist[neighbor])
                {
                    dist[neighbor] = dist[temp.second] + time;
                    ways[neighbor] = ways[temp.second];

                    pq.emplace(dist[neighbor], neighbor);
                }
                else if (dist[temp.second] + time == dist[neighbor])
                {
                    ways[neighbor] = (ways[temp.second] + ways[neighbor]) % (long long)MOD;
                }
            }
        }

        return ways[n - 1];
    }
};

int main()
{
    Solution s;

    cout << s.countPaths(7, {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}});

    return 0;
}