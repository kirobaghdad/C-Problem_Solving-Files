#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     long long countSubarrays(vector<int> nums, int k)
//     {
//         ios::sync_with_stdio(false);
//         cin.tie(nullptr);
//         cout.tie(nullptr);

//         const int maxim = *max_element(nums.begin(), nums.end());
//         int count = 0;
//         long long ans = 0;

//         for (int i = 0, j = 0; j < nums.size(); j++)
//         {
//             if (nums[j] == maxim)
//             {
//                 count++;

//                 if (count == k)
//                 {

//                     while (nums[i] != maxim)
//                     {
//                         i++;
//                         ans += (nums.size() - j);
//                     }

//                     i++;
//                     ans += (nums.size() - j);

//                     count--;
//                 }
//             }
//         }

//         return ans;
//     }
// };

// class Solution
// {
// public:
//     long long countSubarrays(vector<int> nums, int k)
//     {
//         ios::sync_with_stdio(false);
//         cin.tie(nullptr);
//         cout.tie(nullptr);

//         const int maxim = *max_element(nums.begin(), nums.end());
//         int count = 0;
//         long long ans = 0;

//         int temp = 0;

//         for (int i = 0, j = 0; j < nums.size(); j++)
//         {
//             temp += j + 1;

//             if (nums[j] == maxim)
//             {
//                 count++;

//                 if (count == k)
//                 {
//                     // ans++;

//                     while (nums[i] != maxim)
//                         i++;

//                     // ans += i;

//                     i++;
//                     count--;
//                 }
//             }

//             ans += j - i + 1;
//         }

//         return temp - ans;
//     }
// };

class Solution
{
public:
    long long countSubarrays(vector<int> nums, int k)
    {
        int n = nums.size();
        int maxEl = *max_element(nums.begin(), nums.end());
        int left = 0, right = 0;
        long long res = 0, count = 0;
        for (right = 0; right < n; right++)
        {
            if (nums[right] == maxEl)
            {
                count++;
            }
            while (count >= k)
            {
                res += n - right;
                if (nums[left] == maxEl)
                {
                    count--;
                }
                left++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;

    cout << s.countSubarrays({1, 3, 2, 3, 3, 1}, 2);

    return 0;
}