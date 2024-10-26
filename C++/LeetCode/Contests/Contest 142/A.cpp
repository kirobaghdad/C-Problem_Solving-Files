#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int possibleStringCount(string word)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 1;

        char a = word[0];

        for (int i = 1; i < word.size(); i++)
        {
            if (word[i] == word[i - 1])
                ans++;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.possibleStringCount("aaaa");
    return 0;
}