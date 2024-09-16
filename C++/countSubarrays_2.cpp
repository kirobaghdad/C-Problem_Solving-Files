#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> nums, int minK, int maxK)
    {
        int right = 0;
        int left = 0;

        int ans = 0;

        while (left < nums.size())
        {
            while (right < nums.size() && nums[right] >= minK && nums[right] <= maxK)
                right++;

            ans += subarrays(nums, left, right, minK, maxK);

            right++;
            left = right;
        }

        return ans;
    }

    long long subarrays(vector<int> &nums, int left, int right, int minK, int maxK)
    {
        long long count = 0;

        priority_queue<int, vector<int>, greater<int>> minQ;
        priority_queue<int, vector<int>, greater<int>> maxQ;

        for (int i = left; i < right; i++)
        {
            if (nums[i] == minK)
                minQ.push(i);
            if (nums[i] == maxK)
                maxQ.push(i);
        }

        for (int i = left; i < right; i++)
        {
            if (!minQ.size() || !maxQ.size())
                break;
            int x = max(minQ.top(), maxQ.top());
            count += right - x;

            if (minQ.top() == i)
                minQ.pop();
            if (maxQ.top() == i)
                maxQ.pop();
        }

        return count;
    }
};

int main()
{
    Solution s;

    cout << s.countSubarrays({1, 1, 1, 1}, 1, 1);

    return 0;
}