#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int pos = 0;
        int neg = 0;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                pos++;
            else if (nums[i] < 0)
                neg++;

        return max(pos, neg);
    }
};

int main()
{

    return 0;
}