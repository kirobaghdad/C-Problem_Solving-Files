#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long totalCost(vector<int> costs, int k, int can)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> p;

        for (int i = 0; i < can; i++)
        {
            p.push({costs[i], 0});
            if (costs.size() - i - 1 >= can)
                p.push({costs[costs.size() - i - 1], 1});
        }

        int a = can - 1;
        int b = costs.size() - can;

        long long ans = 0;
        pair<int, bool> temp;

        for (int i = 0; i < k; i++)
        {
            temp = p.top();
            p.pop();
            ans += temp.first;

            if (temp.second)
            {
                b--;
                if (b > a)
                {
                    p.push({costs[b], 1});
                }
            }
            else
            {
                a++;
                if (a < b)
                {
                    p.push({costs[a], 0});
                }
            }
        }

        return ans;
    }
};
int main()
{
    Solution s;

    cout << s.totalCost({18, 64, 12, 21, 21, 78, 36, 58, 88, 58, 99, 26, 92, 91, 53, 10, 24, 25, 20, 92, 73, 63, 51, 65, 87, 6, 17, 32, 14, 42, 46, 65, 43, 9, 75}, 13, 22);

    return 0;
}