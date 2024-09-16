#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> ans(n + 1);
        ans[0] = 0;
        ans[1] = 1;

        for (int i = 2; i <= n; i++)
            if (!(i & (i - 1)) == 0)
                ans[i] = ans[pow(2, (int)log2(i))] + ans[i - pow(2, (int)log2(i))];
            else
                ans[i] = 1;

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> ans = s.countBits(8);

    for (auto &it : ans)
        cout << it << endl;

    return 0;
}