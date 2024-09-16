#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

// std::vector<std::vector<int>> subArraySum(std::vector<int> &nums, int k)
// {
//     std::unordered_map<int, std::vector<int>> map;
//     std::vector<std::vector<int>> result;
//     map[0].push_back(-1);
//     int sum = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         sum += nums[i];
//         if (map.find(sum - k) != map.end())
//         {
//             for (int index : map[sum - k])
//             {
//                 if (result.empty() || index + 1 > result.back().front())
//                 {
//                     result.push_back({index + 1, i});
//                 }
//             }
//         }
//         map[sum].push_back(i);
//     }
//     for (auto &pair : result)
//     {
//         pair = std::vector<int>(nums.begin() + pair.front(), nums.begin() + pair.back() + 1);
//     }
//     return result;
// }

// int main()
// {
//     std::vector<int> nums = {1, 2, -3, 3, 1};
//     int k = 0;
//     std::vector<std::vector<int>> result = subArraySum(nums, k);
//     for (const auto &subarray : result)
//     {
//         for (int num : subarray)
//         {
//             std::cout << num << ' ';
//         }
//         std::cout << '\n';
//     }
//     return 0;
// }

// // int main()
// // {
// //     std::vector<int> nums = {5, 1, 2, -3, 3, 1};
// //     int k = 0;
// //     std::vector<std::vector<int>> result = subArraySum(nums, k);
// //     for (const auto &subarray : result)
// //     {
// //         for (int num : subarray)
// //         {
// //             std::cout << num << ' ';
// //         }
// //         std::cout << '\n';
// //     }
// //     return 0;
// // }
#pragma GCC optimize("O3", "unroll-loops")

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode node = ListNode(0, head);
        unordered_map<int, ListNode *> mp; // or use map
        int prefix = 0;
        for (ListNode *ptr = &node; ptr; ptr = ptr->next)
        {
            prefix += (ptr->val);
            mp[prefix] = ptr;
        }
        prefix = 0; // reset
        for (ListNode *ptr = &node; ptr; ptr = ptr->next)
        {
            prefix += (ptr->val);
            ptr->next = mp[prefix]->next;
        }
        return node.next;
    }
};

int main()
{
    Solution s;
    ListNode *l = new ListNode(1, new ListNode(2, new ListNode(-3, new ListNode(3, new ListNode(1)))));

    ListNode *ans = s.removeZeroSumSublists(l);
}