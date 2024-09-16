#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// class Solution
// {

// public:
//     int firstMissingPositive(vector<int> nums)
//     {

//         const int n = nums.size();

//         // Correct slot:

//         // nums[i] = i + 1

//         // nums[i] - 1 = i

//         // nums[nums[i] - 1] = nums[i]

//         for (int i = 0; i < n; ++i)

//             while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])

//                 swap(nums[i], nums[nums[i] - 1]);

//         for (int i = 0; i < n; ++i)

//             if (nums[i] != i + 1)

//                 return i + 1;

//         return n + 1;
//     }
// };

class Solution
{
public:
    int firstMissingPositive(vector<int> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] <= 0)
                nums[i] = nums.size() + 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (abs(nums[i]) <= nums.size())
                nums[abs(nums[i]) - 1] = abs(nums[abs(nums[i]) - 1]) * -1;
        }

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0)
                return i + 1;

        return nums.size() + 1;
    }
};

int main()
{
    Solution s;
    cout << s.firstMissingPositive({3, 4, -1, 1});
    return 0;
}