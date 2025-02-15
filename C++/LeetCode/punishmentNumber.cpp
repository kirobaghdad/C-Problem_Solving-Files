#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool partitionExist(string s, int sum)
    {
        bool a;

        if (s.size() == 1)
        {
            if (sum - stoi(s) == 0)
                return true;
            else
                return false;
        }

        for (int i = 1; i < s.size(); i++)
        {
            if (sum - stoi(s.substr(i, s.size() - i)) - stoi(s.substr(0, i)) == 0)
                return 1;

            a = partitionExist(s.substr(i, s.size() - i), sum - stoi(s.substr(0, i)));

            if (a)
                return true;
        }

        return false;
    }

    int punishmentNumber(int n)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int ans = 1;
        string s;

        for (int i = 2; i <= n; i++)
        {
            s = to_string(i * i);

            if (partitionExist(s, i))
            {
                ans += i * i;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.punishmentNumber(10);

    return 0;
}