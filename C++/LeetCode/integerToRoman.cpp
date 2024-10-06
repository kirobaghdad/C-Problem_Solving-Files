#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        string ans;

        string n = to_string(num);

        for (int i = 0; i < n.size(); i++)
        {
            if (n.size() - i == 4)
            {
                ans += string(n[i] - '0', 'M');
            }
            else if (n.size() - i == 3)
            {
                if (n[i] == '9')
                    ans += "CM";
                else if (n[i] == '4')
                    ans += "CD";
                else
                {
                    if (n[i] >= '5')
                    {
                        ans += 'D';

                        ans += string(n[i] - '5', 'C');
                    }
                    else
                        ans += string(n[i] - '0', 'C');
                }
            }
            else if (n.size() - i == 2)
            {
                if (n[i] == '9')
                    ans += "XC";
                else if (n[i] == '4')
                    ans += "XL";
                else
                {
                    if (n[i] >= '5')
                    {
                        ans += 'L';

                        ans += string(n[i] - '5', 'X');
                    }
                    else
                    {
                        ans += string(n[i] - '0', 'X');
                    }
                }
            }
            else if (n.size() - i == 1)
            {
                if (n[i] == '9')
                    ans += "IX";
                else if (n[i] == '4')
                    ans += "IV";
                else
                {
                    if (n[i] >= '5')
                    {
                        ans += 'V';

                        ans += string(n[i] - '5', 'I');
                    }
                    else
                    {
                        ans += string(n[i] - '0', 'I');
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

    cout << s.intToRoman(1);

    return 0;
}