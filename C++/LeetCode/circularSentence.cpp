#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        istringstream iss(sentence);

        string temp;

        char last = ' ';

        do
        {
            iss >> temp;

            if (iss && last != ' ' && temp[0] != last)
                return false;

            last = temp[temp.size() - 1];

        } while (iss);

        if (temp[temp.size() - 1] != sentence[0])
            return false;

        return true;
    }
};

int main()
{

    Solution s;

    cout << s.isCircularSentence("leetcode exercises sound delightful");

    return 0;
}