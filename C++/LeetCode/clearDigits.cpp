#include <iostream>
#include <bits/stdc++.h>
using namespace std;
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);

class Solution
{
public:
    string clearDigits(string s)
    {
        string ans;

        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                if (ans.size())
                {
                    ans.pop_back();
                }
            }
            else
            {
                ans += s[i];
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}