#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestChair(vector<vector<int>> times, int targetFriend)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        map<int, int> m;
        int targetTime = times[targetFriend][0];

        std::sort(times.begin(), times.end(),
                  [](const std::vector<int> &a, const std::vector<int> &b)
                  {
                      return a[0] < b[0];
                  });

        int c;

        for (int i = 0; i < times.size(); i++)
        {
            c = 0;

            for (auto j = m.begin(); j != m.end(); j++)
            {
                if (j->second > times[i][0])
                    c++;
                else
                {
                    c = j->first;
                    break;
                }
            }

            if (times[i][0] == targetTime)
                break;

            m[c] = times[i][1];
        }

        return c;
    }
};

int main()
{
    Solution s;

    cout << s.smallestChair({{3, 10}, {1, 5}, {2, 6}}, 0);

    return 0;
}