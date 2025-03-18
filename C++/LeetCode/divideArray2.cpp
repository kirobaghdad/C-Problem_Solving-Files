#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        set<int> n;

        for (int i = 0; i < nums.size(); i++)
        {
            if (n.find(nums[i]) != n.end())
            {
                n.erase(nums[i]);
            }
            else
            {
                n.insert(nums[i]);
            }
        }

        return n.empty();
    }
};

int main()
{

    return 0;
}