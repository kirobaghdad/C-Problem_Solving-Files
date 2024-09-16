#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubstring(string t, string s)
    {
        int j = 0;

        for (int i = 0; i < s.size() - 1; i++)
        {
            if (t[j] == s[i])
            {
                j++;
            }
            else
            {
                s.erase(i, 1);
                return s == t;
            }
        }

        return true;
    }

    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const std::string &first, const std::string &second)
             { return first.size() < second.size(); });

        vector<int> ans(words.size(), 1);

        int j;
        int max = 1;

        for (int i = 0; i < words.size(); ++i)
        {
            j = i - 1;

            while (j >= 0)
            {
                if (words[i].size() - words[j].size() == 0)
                {
                    j--;
                }
                else if (words[i].size() - words[j].size() == 1)
                {
                    if (isSubstring(words[j], words[i]))
                    {

                        ans[i] = ans[i] < ans[j] + 1 ? ans[j] + 1 : ans[i];
                        if (ans[i] > max)
                            max = ans[i];
                    }
                    j--;
                }
                else
                    break;
            }
        }

        return max;
    }
};

int main()
{
    Solution s;
    vector<string> v = {"abcd", "dbqca"};

    cout << s.longestStrChain(v);
    return 0;
}