#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int i = 0;

        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                nums[i + 1] = nums[j];
                i++;
            }
        }

        return i + 1;
    }
};
int main()
{

    return 0;
}