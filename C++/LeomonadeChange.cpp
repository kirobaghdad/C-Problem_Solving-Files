#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> bills)
    {
        bool ans = true;

        int c5 = 0;
        int c10 = 0;

        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
                c5++;
            else if (bills[i] == 10)
            {
                if (c5 == 0)
                {
                    ans = false;
                    break;
                }
                else
                    c5--;

                c10++;
            }
            else
            {
                if (c10 == 0)
                {
                    if (c5 < 3)
                    {
                        ans = false;
                        break;
                    }
                    else
                        c5 -= 3;
                }
                else
                {
                    c10--;
                    if (c5 > 0)
                        c5--;
                    else
                    {
                        ans = false;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.lemonadeChange({5, 5, 5, 10, 5, 5, 10, 20, 20, 20});

    return 0;
}