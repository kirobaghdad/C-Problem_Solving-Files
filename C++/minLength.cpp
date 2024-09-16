#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (i < j && s[i] == s[j])
        {
            char t = s[i];

            if (i + 1 == j)
                return 0;

            i++;
            j--;

            while (i + 1 < j && s[i] == t)
                i++;

            while (i + 1 < j && s[j] == t)
                j--;

            // if (i == j)
            //     return 0;
        }

        return j - i + 1;
    }
};

int main()
{
    Solution s;
    cout << s.minimumLength("bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb");

    return 0;
}