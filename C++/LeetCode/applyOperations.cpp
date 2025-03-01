#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        set<int> zeros;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!nums[i])
                zeros.insert(i);
            else
            {
                if (zeros.size())
                {
                    // shift number back
                    nums[*(zeros.begin())] = nums[i];
                    nums[i] = 0;
                    zeros.erase(*(zeros.begin()));
                    zeros.insert(i);
                }
            }
        }

        return nums;
    }
};

int main()
{

    return 0;
}