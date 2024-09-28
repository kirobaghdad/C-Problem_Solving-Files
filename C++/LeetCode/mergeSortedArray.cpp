#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int i = 0;
        int j = 0;

        if (m == 0)
        {
            nums1 = nums2;
            return;
        }
        else if (n == 0)
            return;

        while (i < m)
        {
            if (nums2[0] < nums1[i])
            {
                swap(nums1[i], nums2[0]);

                j = 0;

                while (j + 1 < n && nums2[j] > nums2[j + 1])
                    swap(nums2[j], nums2[1 + j++]);
            }

            i++;
        }

        for (j = 0; j < n; j++)
        {
            nums1[m + j] = nums2[j];
        }

        return;
    }
};

int main()
{

    return 0;
}