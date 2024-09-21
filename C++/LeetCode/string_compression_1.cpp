#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        // int ans = 0;
        int i = 0;
        int j = 1;

        int res = 0;

        // vector<char> a;
        string temp;

        while (j <= chars.size())
        {

            if (j == chars.size() || chars[j] != chars[i])
            {
                chars[res++] = chars[i];

                if (j - i != 1)
                {
                    temp = to_string(j - i);

                    for (int k = 0; k < temp.size(); k++)
                    {
                        chars[res + k] = temp[k];
                    }

                    res += temp.size();
                }

                i = j;
            }

            j++;
        }

        chars.erase(chars.begin() + res, chars.end());

        return res;
    }
};

int main()
{
    Solution s;

    vector<char> t = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};

    cout << s.compress(t);

    return 0;
}