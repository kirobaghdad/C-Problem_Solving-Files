#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> nums)
    {
        int m = *max_element(nums.begin(), nums.end());

        int n = INT_MIN;

        bool check = false;

        for (auto it : nums)
        {
            if (it > n)
                if (!(it == m && check == false))
                    n = it;

            if (it == m)
                check = true;
        }
        return (n - 1) * (m - 1);
    }
};

int main()
{

    Solution s;
    cout << s.maxProduct({3, 4, 5, 2});

    return 0;
}