#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> tokens, int power)
    {
        int j = tokens.size() - 1;
        int i = 0;

        sort(tokens.begin(), tokens.end());

        int ans = 0;

        bool s = 0;

        while (i < j)
        {
            if (power >= tokens[i])
            {
                power -= tokens[i];
                ans++;
                i++;
            }
            else
            {
                if (ans == 0)
                    return 0;
                power += tokens[j];
                ans--;
                j--;
            }
            // if (s == 0)
            // {
            //     if (power >= tokens[i])
            //     {
            //         power -= tokens[i];
            //         ans++;
            //         s = 1;
            //         i++;
            //     }
            //     else
            //     {
            //         power += tokens[j];
            //         ans--;
            //         j--;
            //     }
            // }
            // else
            // {
            //     power += tokens[j];
            //     ans--;
            //     j--;
            //     s = 0;
            // }
        }

        if (i == j && power >= tokens[i])
            ans++;

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.bagOfTokensScore({71, 55, 82}, 54);
    return 0;
}