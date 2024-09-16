#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int i = 0;

        while (i < word.size())
        {
            if (ch == word[i])
                break;

            i++;
        }

        if (i != word.size())
            reverse(word.begin(), word.begin() + i + 1);

        return word;
    }
};

int main()
{
    Solution s;

    cout << s.reversePrefix("abcd", 'z');
    return 0;
}