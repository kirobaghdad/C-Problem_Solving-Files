#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int i = 0;
        int j = s.size() - 1;

        while (i < j)
        {
            if (iswalnum(s[i]))
            {
                if (iswalnum(s[j]))
                {

                    if (tolower(s[i]) == tolower(s[j]))
                    {
                        i++;
                        j--;
                    }
                    else
                        return false;
                }
                else
                    j--;
            }
            else
                i++;
        }

        return true;
    }
};

int main()
{
    Solution s;

    cout << s.isPalindrome("A man, a plan, a canal: Panama");

    return 0;
}