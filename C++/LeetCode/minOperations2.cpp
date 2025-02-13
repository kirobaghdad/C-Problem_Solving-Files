#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &can, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        // making min queue
        priority_queue<long long, vector<long long>, greater<long long>> pq(can.begin(), can.end());

        long long temp;
        int ans = 0;

        while (pq.top() < k)
        {
            temp = pq.top() * 2;
            pq.pop();

            temp += pq.top();
            pq.pop();

            pq.push(temp);
            ans++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}