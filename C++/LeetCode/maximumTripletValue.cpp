#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long ans = 0;
        long long temp;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    temp = (nums[i] - nums[j]) * (long long)nums[k];

                    if (temp > ans)
                        ans = temp;
                }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}