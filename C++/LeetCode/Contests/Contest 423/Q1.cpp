#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasIncreasingSubarrays(vector<int> nums, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        bool aFound = false;
        int c = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            c = 0;

            for (int j = i; j < nums.size(); j++)
            {
                if (j == i || nums[j] > nums[j - 1])
                    c++;
                else
                    break;

                if (c == k)
                    break;
            }

            if (c == k)
            {
                c = 0;

                for (int j = i + k; j < nums.size(); j++)
                {
                    if (j == i + k || nums[j] > nums[j - 1])
                        c++;
                    else
                        break;

                    if (c == k)
                        break;
                }

                if (c == k)
                    return true;
            }
        }

        return false;
    }
};
int main()
{
    Solution s;

    cout << s.hasIncreasingSubarrays({2, 5, 7, 8, 9, 2, 3, 4, 3, 1}, 3);
    return 0;
}