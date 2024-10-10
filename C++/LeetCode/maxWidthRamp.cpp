#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxWidthRamp(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        // Solve using monotonic stack

        stack<int> s;

        s.push(0);
        int temp;

        int ans = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            temp = nums[s.top()];

            if (nums[i] < temp)
            {
                s.push(i);
            }
            else
            {
                stack<int> t;

                while (nums[i] >= temp)
                {
                    ans = max(ans, i - s.top());
                    t.push(s.top());
                    s.pop();

                    if (s.size())
                    {
                        temp = nums[s.top()];
                    }
                    else
                    {
                        break;
                    }
                }

                while (t.size())
                {
                    temp = t.top();
                    s.push(temp);
                    t.pop();
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.maxWidthRamp({6, 0, 8, 2, 1, 5});
    return 0;
}