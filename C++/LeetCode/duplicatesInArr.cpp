#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> nums)
    {
        vector<int> answer;

        for (int i = 0; i < nums.size(); i++)
        {
            nums[(nums[i] - 1) % nums.size()] += nums.size();
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] / float(nums.size()) > 2)
            {
                answer.push_back(i + 1);
            }
        }
        return answer;
    }
};

int main()
{
    Solution s;

    vector<int> ans = s.findDuplicates({4, 3, 2, 7, 8, 2, 3, 1});

    for (auto it : ans)
        cout << it << endl;

    return 0;
}