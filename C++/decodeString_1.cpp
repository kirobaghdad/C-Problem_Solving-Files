#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        string ans;

        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                int j = i + 1;

                while (isdigit(s[j]))
                    j++;

                string num = s.substr(i, j - i);

                // beginning
                int k = ++j;

                int c = 1;

                while (c != 0)
                {
                    if (s[j] == '[')
                        c++;
                    else if (s[j] == ']')
                        c--;

                    j++;
                }

                string temp = decodeString(s.substr(k, j - k - 1));

                for (k = 0; k < stoi(num); k++)
                    ans += temp;

                j--;

                i = j;
            }
            else
                ans += s[i];
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.decodeString("3[a2[c]]");

    return 0;
}