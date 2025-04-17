#include <iostream>
#include <bits/stdc++.h>
using namespace std;
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j] && (i * j) % k == 0)
                    ans++;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}