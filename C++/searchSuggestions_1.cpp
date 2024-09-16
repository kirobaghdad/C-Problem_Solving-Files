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

        vector<vector<string>> ans(searchWord.size());

        int s = 0;
        int e = products.size() - 1;

        for (int i = 0; i < searchWord.size(); i++)
        {

            while (s < products.size() && (i >= products[s].size() || products[s][i] < searchWord[i]))
                s++;

            while (e >= 0 && (i >= products[e].size() || products[e][i] > searchWord[i]))
                e--;

            if (e < s)
                break;

            ans[i] = (vector<string>(products.begin() + s, e - s >= 3 ? products.begin() + s + 3 : products.begin() + e + 1));
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