#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        stringstream ss(sentence);

        string word;

        int i = 1;

        while (ss >> word)
        {
            if (word.substr(0, searchWord.length()) == searchWord)
                return i;

            i++;
        }

        return -1;
    }
};

int main()
{

    return 0;
}