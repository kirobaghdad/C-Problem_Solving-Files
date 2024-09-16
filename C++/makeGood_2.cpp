#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_bad(char a, char b)
    {
        return islower(a) && isupper(b) && tolower(b) == a;
    }
    string makeGood(string s)
    {

        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        string st;
        for (char c : s)
        {
            if (!st.empty() && (is_bad(c, st.back()) || is_bad(st.back(), c)))
                st.pop_back();
            else
                st.push_back(c);
        }
        return st;
    }
};

int main()
{

    Solution s;

    cout << s.makeGood("abBAcC");

    return 0;
}