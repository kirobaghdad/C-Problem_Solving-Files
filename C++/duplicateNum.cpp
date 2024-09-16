#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> nums)
    {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] == nums[j])
                {
                    ans = nums[i];
                    break;
                }

            if (ans)
                break;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.findDuplicate({1, 3, 4, 2, 2});

    return 0;
}