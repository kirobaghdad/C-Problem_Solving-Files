#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string ans;
    const set<char> h = {'a', 'b', 'c'};

    void solve(int n, int k, int &ind, string temp = "")
    {
        if (ind == k)
        {
            return;
        }

        if (temp.size() == n)
        {
            ind++;

            if (ind == k)
                ans = temp;

            return;
        }

        for (auto &it : h)
        {
            if (temp == "" || (temp[temp.size() - 1] != it))
            {
                solve(n, k, ind, temp + it);
            }
        }
    }

    string getHappyString(int n, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int ind = 0;

        solve(n, k, ind);

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.getHappyString(3, 9);
    return 0;
}