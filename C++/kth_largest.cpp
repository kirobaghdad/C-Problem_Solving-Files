#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void heapify(vector<int> &arr, int N, int i)
    {
        int largest = i;   // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (l < N && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < N && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i)
        {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, N, largest);
        }
    }

    // Function to build a Max-Heap from the given array
    void buildHeap(vector<int> &arr, int N)
    {
        // Index of last non-leaf node
        int startIdx = (N / 2) - 1;

        // Perform reverse level order traversal
        // from last non-leaf node and heapify
        // each node
        for (int i = startIdx; i >= 0; i--)
        {
            heapify(arr, N, i);
        }
    }

    void deleteRoot(vector<int> &arr, int n)
    {
        // Get the last element
        int lastElement = arr[n - 1];

        // Replace root with last element
        arr[0] = lastElement;

        // Decrease size of heap by 1
        arr.erase(arr.end() - 1);

        // heapify the root node
        heapify(arr, n, 0);
    }

    int findKthLargest(vector<int> nums, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        buildHeap(nums, nums.size());

        for (int i = 1; i < k; i++)
            deleteRoot(nums, nums.size());

        return nums[0];
    }
};

int main()
{
    Solution s;

    cout << s.findKthLargest({-1, 2, 0}, 3);

    return 0;
}