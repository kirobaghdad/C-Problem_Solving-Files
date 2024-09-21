#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int twoEggDrop(int n)
    {
        vector<int> nums;
        nums.push_back(n);

        int j = 1;

        for (int i = n - j; i > 0; i = i - j)
        {
            nums.push_back(i);
            j++;
        }

        int ans = INT_MIN;

        int drops = 1;

        int prev = 0;

        for (auto it = nums.rbegin(); it != nums.rend(); it++)
        {
            ans = max(ans, *it - prev - 1 + drops);
            prev = *it;
            drops++;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.twoEggDrop(100);

    return 0;
}