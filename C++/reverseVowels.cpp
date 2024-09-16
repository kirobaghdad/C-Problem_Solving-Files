#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        string vowels;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                vowels += s[i];
        }

        int j = vowels.size() - 1;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                s[i] = vowels[j];
                j--;
            }
        }

        return s;
    }
};

int main()
{
    Solution s;
    cout << s.reverseVowels("Hello");

    return 0;
}