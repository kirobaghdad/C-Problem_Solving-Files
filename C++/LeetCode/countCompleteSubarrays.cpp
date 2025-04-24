#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int k = unordered_set(nums.begin(), nums.end()).size();
        unordered_map<int, int> m;

        int left = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;

            while (m.size() == k)
            {
                ans += nums.size() - i;

                m[nums[left]]--;

                if (m[nums[left]] == 0)
                    m.erase(nums[left]);

                left++;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}