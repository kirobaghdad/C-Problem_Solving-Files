#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> code, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> ans(code.size(), 0);

        for (int i = 0; i < code.size(); i++)
        {
            if (k == 0)
                ans[i] = 0;
            else if (k > 0)
            {
                for (int j = 1; j <= k; j++)
                {
                    ans[i] += code[(i + j) % code.size()];
                }
            }
            else
            {
                for (int j = 1; j <= abs(k); j++)
                {
                    if (i - j < 0)
                        ans[i] += code[code.size() - (i - j)];
                    else
                        ans[i] += code[(i - j) % code.size()];
                }
            }
        }

        return ans;
    }
};
int main()
{
    Solution s;

    s.decrypt({10, 5, 7, 7, 3, 2, 10, 3, 6, 9, 1, 6}, -4);
    return 0;
}