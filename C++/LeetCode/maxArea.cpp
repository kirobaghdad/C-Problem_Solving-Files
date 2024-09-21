#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> height)
    {
        int currentArea = 0, maxArea = 0;

        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(currentArea, maxArea);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxArea;
    }

    // Wrong Solution
    // int maxArea(vector<int> height)
    // {
    //     // pair<int, int> max(0, height[]);
    //     int max = 0;

    //     int maxArea = 0;

    //     for (int i = 1; i < height.size(); i++)
    //     {
    //         if (min(height[max], height[i]) * (i - max) > maxArea)
    //             maxArea = min(height[max], height[i]) * (i - max);

    //         if (height[i] * 1 == height[max] * (i - max + 1))
    //         {
    //             if (i < height.size() - 1)
    //             {
    //                 if (height[i + 1] > height[i])
    //                     max = height[max] > height[i] ? max : i;
    //                 else
    //                     max = height[max] < height[i] ? max : i;
    //             }
    //         }
    //         else if (height[i] * 1 > height[max] * (i - max + 1))
    //             max = i;
    //     }

    //     return maxArea;
    // }
};

int main()
{

    Solution s;
    cout << s.maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7});

    return 0;
}