#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        string temp;
        vector<vector<string>> ans;
        map<string, vector<string>> m;

        for (int i = 0; i < strs.size(); i++)
        {
            temp = strs[i];
            sort(temp.begin(), temp.end());

            (m[temp]).push_back(strs[i]);
        }

        for (auto it : m)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main()
{

    return 0;
}