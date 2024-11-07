#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestCombination(vector<int> &can)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 0;
        int temp = 0;

        bool bit;

        for (int j = 0; j < 24; j++)
        {
            temp = 0;

            for (int i = 0; i < can.size(); i++)
            {
                bit = can[i] % 2;
                can[i] /= 2;

                temp += bit;
            }

            ans = max(ans, temp);
        }

        return ans;
    }
};
int main()
{

    return 0;
}