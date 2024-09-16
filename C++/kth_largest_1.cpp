#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void heapify(vector<int> &nums, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < nums.size() && nums[l] > nums[largest])
            largest = l;

        if (r < nums.size() && nums[r] > nums[largest])
            largest = r;

        if (largest != i)
        {
            swap(nums[largest], nums[i]);

            heapify(nums, largest);
        }
    }

    void buildHeap(vector<int> &nums)
    {
        int l = nums.size() / 2 - 1;

        for (int i = l; i >= 0; i--)
            heapify(nums, i);
    }

    void removeLast(vector<int> &nums)
    {
        nums[0] = nums[nums.size() - 1];

        nums.erase(nums.end() - 1);

        buildHeap(nums);
    }

    int findKthLargest(vector<int> nums, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        buildHeap(nums);

        for (int i = 1; i < k; i++)
            removeLast(nums);

        return nums[0];
    }
};

int main()
{
    Solution s;
    cout << s.findKthLargest({3, 2, 1, 5, 6, 4}, 2);

    return 0;
}