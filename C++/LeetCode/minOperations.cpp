#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minOperations(vector<int> nums1, vector<int> nums2, int k)
    {
        int sum = 0;

        int ans = 0;

        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] > nums2[i])
                if ((nums1[i] - nums2[i]) % k != 0)
                {
                    ans = -1;
                    break;
                }
                else
                {
                    sum += (nums1[i] - nums2[i]) / k;
                    ans += (nums1[i] - nums2[i]) / k;
                }
            else if (nums1[i] < nums2[i])
                if ((nums2[i] - nums1[i]) % k != 0)
                {
                    ans = -1;
                    break;
                }
                else
                    sum -= (nums2[i] - nums1[i]) / k;
        }

        return sum == 0 ? ans : -1;
    }
};

int main()
{
    Solution s;

    cout << s.minOperations({13, 6, 10, 16}, {1, 16, 12, 16}, 2);
    return 0;
}