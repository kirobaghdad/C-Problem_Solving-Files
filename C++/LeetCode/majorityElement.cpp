#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_map<int, int> n;

        for (auto it : nums)
        {
            n[it]++;

            if (n[it] > nums.size() / 2)
                return it;
        }

        return -1;
    }
};

int main()
{

    return 0;
}