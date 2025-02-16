#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> ans;

    bool solve(vector<int> temp, set<int> nums, int i = 0)
    {
        if (i >= temp.size())
        {
            ans = temp;
            return true;
        }

        set<int> t;

        if (!temp[i])
            for (auto it = nums.rbegin(); it != nums.rend(); it++)
            {
                if (*it != 1 && (i + *it >= temp.size()))
                    continue;

                if (*it == 1 || (i + *it < temp.size() && temp[i + *it] == 0))
                {
                    t = nums;
                    t.erase(*it);

                    temp[i] = *it;

                    if (*it != 1)
                        temp[i + *it] = *it;

                    if (solve(temp, t, i + 1))
                        return true;

                    if (*it != 1)
                        temp[i + *it] = 0;

                    temp[i] = 0;
                }
            }
        else if (solve(temp, nums, i + 1))
            return true;

        return false;
    }

    vector<int> constructDistancedSequence(int n)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        set<int> nums;

        nums.insert(1);

        for (int i = 2; i <= n; i++)
        {
            nums.insert(i);
        }

        solve(vector<int>((n - 1) * 2 + 1, 0), nums);

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> ans = s.constructDistancedSequence(11);

    for (auto it : ans)
        cout << it << endl;
    return 0;
}