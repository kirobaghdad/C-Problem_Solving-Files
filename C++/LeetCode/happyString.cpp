#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        priority_queue<pair<int, char>> pq;

        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});

        string ans;

        pair<int, char> temp, t;

        while (pq.size())
        {
            temp = pq.top();
            pq.pop();

            if (ans.size() >= 2 && ans.back() == temp.second && ans[ans.size() - 2] == temp.second)
            {
                if (pq.size())
                {
                    t = temp;
                    temp = pq.top();
                    pq.pop();

                    pq.push(t);
                }
                else
                    break;
            }

            ans += temp.second;

            temp.first--;

            if (temp.first)
                pq.push({temp.first, temp.second});
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.longestDiverseString(0, 8, 11);

    return 0;
}