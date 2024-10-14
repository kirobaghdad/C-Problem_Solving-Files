#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        priority_queue<int> pq;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }

        long long ans = 0;
        int temp;

        while (k--)
        {
            temp = pq.top();

            ans += temp;

            pq.pop();

            pq.push(ceil((temp + 0.0) / 3.0));
        }

        return ans;
    }
};

int main()
{

    return 0;
}