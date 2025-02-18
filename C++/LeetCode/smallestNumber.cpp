#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string ans;

    void solve(string &pattern, string temp, set<int> &nums, int i = 1)
    {
        if (ans != "")
            return;

        if (i == pattern.size() + 1)
        {
            ans = temp;
            return;
        }

        if (pattern[i - 1] == 'I')
        {
            for (int j = (temp[i - 1]) - '0' + 1; j <= 9; j++)
            {
                if (nums.find(j) != nums.end())
                {
                    nums.erase(j);
                    solve(pattern, temp + to_string(j), nums, i + 1);
                    nums.insert(j);
                }
            }
        }
        else
        {
            for (int j = (temp[i - 1]) - '0' - 1; j >= 0; j--)
            {
                if (nums.find(j) != nums.end())
                {
                    nums.erase(j);
                    solve(pattern, temp + to_string(j), nums, i + 1);
                    nums.insert(j);
                }
            }
        }
    }

    string smallestNumber(string pattern)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        set<int> nums;

        for (int i = 1; i <= 9; i++)
            nums.insert(i);

        for (int i = 1; i <= 9; i++)
        {
            nums.erase(i);
            solve(pattern, to_string(i), nums);
            nums.insert(i);
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.smallestNumber("DDD");

    return 0;
}