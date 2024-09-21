#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        string ans;

        int i = s.size() - 1;

        while (i >= 0)
        {
            int j = i;

            while (i != -1 && s[i] != ' ')
                i--;

            if (j != i)
            {
                ans += s.substr(i + 1, j - i);
                ans += " ";
            }

            i--;
        }

        if (ans.size())
            ans.pop_back();

        return ans;
    }
};

int main()
{

    Solution s;

    cout << s.reverseWords("the sky is blue");

    return 0;
}