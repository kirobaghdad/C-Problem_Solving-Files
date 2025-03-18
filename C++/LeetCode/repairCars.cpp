#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long repairCars(vector<int> ranks, int cars)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        long long ans = INT_MAX;
        // *min_element(ranks.begin(), ranks.end()) * cars * cars
        long long left = 1;
        long long right = (long long)*max_element(ranks.begin(), ranks.end()) * cars * cars;

        long long mid;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            long long count = 0;

            for (auto &it : ranks)
            {
                count += sqrt(mid / it);
            }

            if (count >= cars)
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}