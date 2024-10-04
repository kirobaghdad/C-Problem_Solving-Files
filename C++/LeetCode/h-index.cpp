#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(citations.begin(), citations.end());

        int ans = 1;

        for (int i = 0; i < citations.size(); i++)
        {
            if (citations.size() - i >= citations[i])
                ans = citations[i];
            else
            {
                int temp = min(citations[i], (int)citations.size() - i);
                ans = max(temp, ans);
                break;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}