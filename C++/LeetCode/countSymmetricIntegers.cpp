#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int ans = 0;

        string s;

        int i = low;

        if (s.size() % 2)

            int size;

        while (i <= high)
        {
            s = to_string(i);

            if (s.size() % 2 == 1)
            {
                int x = (log10(i) + 1);
                i = pow(10, x);
            }
            else
            {
                int temp0 = 0, temp1 = 0;

                for (int j = 0; j < s.size() / 2; j++)
                {
                    temp0 += s[j] - '0';
                }

                for (int j = s.size() / 2; j < s.size(); j++)
                {
                    temp1 += s[j] - '0';
                }

                if (temp0 == temp1)
                    ans++;

                i++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.countSymmetricIntegers(2, 11);

    return 0;
}