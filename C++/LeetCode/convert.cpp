#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        string ans;

        const int x = 2 * (numRows - 1);

        int j, k;

        for (int i = 0; i < numRows; i++)
        {
            j = i;

            k = 2 * i;

            while (j < s.size())
            {
                ans += s[j];

                if (i == 0 || i == numRows - 1)
                    j += x;

                else
                {
                    k = x - k;
                    j += k;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.convert("AB", 2);

    return 0;
}