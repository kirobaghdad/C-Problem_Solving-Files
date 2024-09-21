#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int k = 0;

        vector<int> temp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                k++;
                temp.push_back(nums[i]);
            }
        }

        nums = temp;

        return k;
    }
};

int main()
{
    Solution s;
    vector<int> t = {3, 2, 2, 3};

    cout << s.removeElement(t, 3);

    return 0;
}