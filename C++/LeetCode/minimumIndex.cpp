#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumIndex(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> front(nums.size(), -1), back(nums.size(), -1);

        map<int, int> m;

        int mx = -1, prevMx = -1;
        int ind = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;

            if (m[nums[i]] > mx)
            {
                prevMx = mx;
                mx = m[nums[i]];
                ind = i;
            }

            if (prevMx != mx)
            {
                if (mx > (i + 1) / 2)
                    front[i] = nums[ind];
            }
        }

        m.clear();
        prevMx = -1, mx = -1;
        ind = -1;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            m[nums[i]]++;

            if (m[nums[i]] > mx)
            {
                prevMx = mx;
                mx = m[nums[i]];
                ind = i;
            }

            if (prevMx != mx)
            {
                if (mx > (nums.size() - i) / 2)
                    back[i] = nums[ind];
            }
        }

        int ans = -1;


        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (front[i] != -1 && front[i] == back[i + 1])
            {
                ans = i;
                break;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.minimumIndex({2, 1, 3, 1, 1, 1, 7, 1, 2, 1}) << endl;

    return 0;
}