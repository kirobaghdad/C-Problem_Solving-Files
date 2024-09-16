#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> spells, vector<int> potions, long long success)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> ans(spells.size());

        sort(potions.begin(), potions.end());

        for (int i = 0; i < spells.size(); i++)
        {
            // Use binary Search
            int j = potions.size() / 2;
            int s = 0;
            int e = potions.size() - 1;

            while (true)
            {
                if (((long long)spells[i] * (long long)potions[j]) >= success)
                {

                    if (j == 0 || ((long long)spells[i] * (long long)potions[j - 1]) < success)
                    {
                        ans[i] = potions.size() - j;
                        break;
                    }
                    else
                    {
                        e = j;
                        j = (e + s) / 2;
                    }
                }
                else if (((long long)spells[i] * (long long)potions[j]) < success)
                {
                    if (j == potions.size() - 1 || ((long long)spells[i] * (long long)potions[j + 1]) >= success)
                    {
                        ans[i] = potions.size() - j - 1;
                        break;
                    }
                    else
                    {
                        s = j;
                        j = ceil((e + s) / 2.0);
                    }
                }
            }

            // for(int j = 0; j < potions.size(); j++)
            //     if(((long long)spells[i] * (long long)potions[j]) >= success)
            //     {
            //         ans[i] = potions.size() - j;
            //         break;
            //     }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    s.successfulPairs({5, 1, 3}, {1, 2, 3, 4, 5}, 7);

    return 0;
}