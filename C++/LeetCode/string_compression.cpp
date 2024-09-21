#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compress(vector<char> chars)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int srt = 0;
        char temp = chars[0];

        for (int i = 1; i <= chars.size(); i++)
        {
            if (i == chars.size() || chars[i] != temp)
            {
                chars.erase(chars.begin() + srt + 1, chars.begin() + i);
                if (i - srt > 1)
                {
                    string s = to_string(i - srt);
                    chars.insert(chars.begin() + srt + 1, s.begin(), s.end());
                    i = srt + s.size();
                    srt = i + 1;

                    if (srt == chars.size())
                        break;

                    if (i + 1 < chars.size())
                        temp = chars[i + 1];
                }
                else
                {
                    srt = i;
                    temp = chars[i];
                }
            }
        }

        return chars.size();
    }
};

int main()
{
    Solution s;

    cout << s.compress({'a', 'b', 'c'});

    return 0;
}