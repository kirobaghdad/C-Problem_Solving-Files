#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestNiceSubarray(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 1;

        map<int, int> bits;
        int bit;
        int temp;
        int k;
        int i = 0;
        int t;

        for (int j = 0; j < nums.size(); j++)
        {
            temp = nums[j];
            k = 0;
            t = -1;

            while (temp)
            {
                if (temp % 2 == 1)
                {
                    // check if this bit already exists
                    if (bits.find(k) != bits.end())
                    {
                        t = max(t, bits[k]);
                    }

                    bits[k] = j;
                }

                k++;
                temp = temp / 2;
            }

            if (t != -1)
            {
                bits.clear();
                i = t + 1;
                j = t;
            }
            else
                ans = max(ans, j - i + 1);
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.longestNiceSubarray({3, 1, 5, 11, 13});

    return 0;
}