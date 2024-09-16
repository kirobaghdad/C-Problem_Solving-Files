#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> people, int limit)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        map<int, int> m;
        int ans = 0;

        for (int i = 0; i < people.size(); i++)
        {
            m[people[i]]++;
        }

        int proc = 0;

        while (proc < people.size())
        {
            int t = (m.rbegin())->first;
            (m.rbegin())->second--;
            int currSum = t;
            proc++;

            if (!m.rbegin()->second)
                m.erase(m.rbegin()->first);

            for (int i = limit - currSum; i >= 1; i--)
            {
                auto it = m.find(i);
                if (it != m.end())
                {
                    if (it->second)
                    {
                        currSum += it->first;
                        it->second--;
                        proc++;

                        if (!it->second)
                        {
                            it = m.end();
                            m.erase(i);
                        }
                    }
                    i = -1;
                }
                if (i == -1)
                    break;
            }

            ans++;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.numRescueBoats({3, 2, 3, 2, 2}, 6);
    return 0;
}
