#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> nums, int minK, int maxK)
    {
        long long ans = 0;
        int left = 0, right = 0;

        while (right < nums.size())
        {
            while (right < nums.size() && nums[right] >= minK && nums[right] <= maxK)
            {
                right++;
            }

            ans = ans + subCount(left, right, nums, minK, maxK);
            right++;
            left = right;
        }

        return ans;
    }

    long long subCount(int left, int right, vector<int> &nums, int minK, int maxK)
    {
        priority_queue<int, vector<int>, greater<int>> pqMinK;
        priority_queue<int, vector<int>, greater<int>> pqMaxK;
        long long count = 0;

        for (int i = left; i < right; i++)
        {
            if (nums[i] == minK)
                pqMinK.push(i);
            if (nums[i] == maxK)
                pqMaxK.push(i);
        }

        for (int i = left; i < right; i++)
        {
            if (pqMinK.size() == 0 || pqMaxK.size() == 0)
                break;
            int x = max(pqMinK.top(), pqMaxK.top());
            count = count + (right - x);

            if (pqMinK.top() == i)
                pqMinK.pop();
            if (pqMaxK.top() == i)
                pqMaxK.pop();
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