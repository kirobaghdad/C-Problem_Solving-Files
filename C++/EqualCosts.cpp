#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int left(int n)
    {
        return 2 * n + 1;
    }

    int right(int n)
    {
        return 2 * n + 2;
    }

    int minIncrements(int n, vector<int> cost)
    {
        int h = log2(n + 1);
        int ans = 0;

        int end = n;
        int start;

        while (h > 1)
        {
            end = end - pow(2, h - 1);
            start = end - pow(2, h - 2);

            for (int i = start; i < end; i++)
            {
                ans += abs(cost[right(i)] - cost[left(i)]);
                cost[i] += max(cost[right(i)], cost[left(i)]);
            }

            h--;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.minIncrements(15, {764, 1460, 2664, 764, 2725, 4556, 5305, 8829, 5064, 5929, 7660, 6321, 4830, 7055, 3761});

    return 0;
}