#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 0;
        int curr = 0;

        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W')
                curr++;
        }

        ans = curr;

        for (int i = k; i < blocks.size(); i++)
        {
            if (blocks[i] == 'W')
                curr++;

            if (blocks[i - k] == 'W')
                curr--;

            ans = min(ans, curr);
        }

        return ans;
    }
};

int main()
{

    return 0;
}