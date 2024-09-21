#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPalindrome(string s, int i, int j)
    {
        string temp = s;

        while (j > i)
        {
            swap(temp[i], temp[j]);
            i++;
            j--;
        }
        return temp == s;
    }

    bool validPalindrome(string s)
    {
        bool ans = true;

        int i = 0;
        int j = s.size() - 1;

        bool adv = false;

        while (j > i)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                bool a = 0, b = 0;

                if (s[i] == s[j - 1])
                {
                    a = checkPalindrome(s, i, j - 1);
                }

                if (s[i + 1] == s[j])
                {
                    b = checkPalindrome(s, i + 1, j);
                }

                ans = a || b;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.validPalindrome("abc");
    return 0;
}