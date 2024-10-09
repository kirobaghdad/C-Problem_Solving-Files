#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> r)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> temp(r.size(), 1);

        if (r.size() == 1)
            return 1;
        for (int i = 1; i < r.size(); i++)
        {
            if (r[i] > r[i - 1])
                temp[i] = temp[i - 1] + 1;
        }

        for (int i = r.size() - 2; i >= 0; i--)
        {
            if (r[i] > r[i + 1])
                temp[i] = max(temp[i], temp[i + 1] + 1);
        }

        return accumulate(temp.begin(), temp.end(), 0);
    }
};

int main()
{
    Solution s;

    cout << s.candy({29, 51, 87, 87, 72, 12});

    return 0;
}