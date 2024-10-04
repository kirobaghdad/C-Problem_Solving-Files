#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {

        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int i = s.size() - 1;
        int len = 0;

        while (s[i] == ' ')
            i--;

        while (i >= 0 && s[i] != ' ')
        {
            i--;
            len++;
        }

        return len;
    }
};
int main()
{

    return 0;
}