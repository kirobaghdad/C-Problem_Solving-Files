#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &n, int target)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int i = 0, j = n.size() - 1;
        vector<int> ans;

        while (i < j && n[i] + n[j] != target)
        {
            if (n[i] + n[j] > target)
                j--;
            else
                i++;
        }

        ans.push_back(i + 1);
        ans.push_back(j + 1);

        return ans;
    }
};

int main()
{

    return 0;
}