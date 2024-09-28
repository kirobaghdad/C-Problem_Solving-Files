#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int i = 0;
        int j = 0;

        while (i < nums.size())
        {
            if (nums[i] != val)
            {
                if (i != j)
                    nums[j] = nums[i];
            }
            else
            {
                j--;
            }

            i++;
            j++;
        }

        return j;
    }
};

int main()
{

    return 0;
}