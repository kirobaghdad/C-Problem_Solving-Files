#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        string ans;

        int a = 0;
        int b = 2 * numRows - 2;

        bool first = false;

        if (numRows == 1)
            return s;

        for (int i = 0; i < numRows; i++)
        {
            int j = i;

            while (j < s.size())
            {
                ans += s[j];

                if (first)
                {
                    if (a == 0)
                    {
                        j += b;
                    }
                    else
                        j += a;
                }
                else
                {

                    if (b == 0)
                    {
                        j += a;
                    }
                    else
                        j += b;
                }

                first = !first;
            }
            a += 2;
            if (i == numRows - 2)
                b = 0;
            else
                b -= 2;

            first = false;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.convert("PAYPALISHIRING", 5);

    return 0;
}