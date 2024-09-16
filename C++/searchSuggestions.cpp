#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> products, string searchWord)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        int left = 0, right = products.size() - 1;

        for (int i = 0; i < searchWord.length(); i++)
        {
            char c = searchWord[i];
            vector<string> res;

            while (left <= right && (products[left].size() <= i || products[left][i] < c))
                left++;
            while (left <= right && (products[right].size() <= i || products[right][i] > c))
                right--;

            for (int j = 0; j < 3 && left + j <= right; j++)
            {
                res.push_back(products[left + j]);
            }
            ans.push_back(res);
        }

        return ans;
    }
};

int main()
{
    Solution s;

    s.suggestedProducts({"mobile", "mouse", "moneypot", "monitor", "mousepad"}, "mouse");

    return 0;
}