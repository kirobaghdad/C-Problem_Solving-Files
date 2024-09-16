#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxInSub(const vector<int> &subArray, int len)
    {
        if (subArray.size() < len)
            return INT_MIN;

        int sum = 0;

        int max;

        for (int i = 0; i < len; i++)
        {
            sum += subArray[i];
        }

        max = sum;

        for (int i = 1; i + len - 1 < subArray.size(); i++)
        {
            sum += subArray[i + len - 1] - subArray[i - 1];

            if (sum > max)
                max = sum;
        }

        return max;
    }

    int maxSumTwoNoOverlap(vector<int> nums, int firstLen, int secondLen)
    {

        int sumFirst = 0;

        int maximum = 0;

        for (int i = 0; i < firstLen; i++)
            sumFirst += nums[i];

        for (int j = 0; j <= nums.size() - firstLen; j++)
        {
            if (j != 0)
                sumFirst += nums[j + firstLen - 1] - nums[j - 1];

            int secondSum = max(maxInSub(vector<int>(nums.begin() + j + firstLen, nums.end()), secondLen),
                                maxInSub(vector<int>(nums.begin(), nums.begin() + j), secondLen));

            maximum = max(maximum, sumFirst + secondSum);
        }

        return maximum;
    }
};

int main()
{
    Solution s;

    cout << s.maxSumTwoNoOverlap({12, 8, 12, 18, 19, 10, 17, 20, 6, 8, 13, 1, 19, 11, 5}, 3, 6);

    return 0;
}