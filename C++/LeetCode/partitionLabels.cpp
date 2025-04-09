#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        map<char, int> m;

        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]] = i;
        }

        vector<int> res;

        int start = 0;

        while (start < s.size())
        {
            int end = m[s[start]];

            int j = start + 1;

            while (j < end)
            {
                end = max(end, m[s[j]]);
                j++;
            }

            res.push_back(end - start + 1);

            start = end + 1;
        }

        return res;
    }
};

int main()
{
    Solution s;

    s.partitionLabels("ababcbacadefegdehijhklij");

    return 0;
}