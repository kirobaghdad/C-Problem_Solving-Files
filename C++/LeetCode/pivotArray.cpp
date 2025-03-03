#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> less, greater;
        int eq = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > pivot)
                greater.push_back(nums[i]);
            else if (nums[i] < pivot)
                less.push_back(nums[i]);
            else
                eq++;
        }

        vector<int> equal = vector<int>(eq, pivot);

        less.insert(less.end(), equal.begin(), equal.end());
        less.insert(less.end(), greater.begin(), greater.end());

        return less;
    }
};

int main()
{

    return 0;
}