#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> asteroids)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        stack<int> temp;
        int t;

        for (int i = 0; i < asteroids.size(); i++)
        {
            bool add = true;

            if (asteroids[i] < 0)
                while (temp.size())
                {
                    t = temp.top();

                    if (t > 0)
                    {
                        if (t > abs(asteroids[i]))
                        {
                            add = false;
                            break;
                        }
                        else if (t < abs(asteroids[i]))
                        {
                            temp.pop();
                        }
                        else
                        {
                            add = false;
                            temp.pop();
                            break;
                        }
                    }
                    else
                        break;
                }

            if (add)
                temp.push(asteroids[i]);
        }

        vector<int> ans(temp.size());

        int i = temp.size() - 1;

        while (temp.size())
        {
            t = temp.top();
            ans[i] = t;
            i--;
            temp.pop();
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> ans = s.asteroidCollision({10, 2, -5});

    for (auto &it : ans)
        cout << it << endl;

    return 0;
}