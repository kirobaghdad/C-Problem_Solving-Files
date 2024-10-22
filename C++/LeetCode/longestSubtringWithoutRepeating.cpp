#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        map<char, int> m;
        int ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (m.count(s[i]) == 0)
            {
                m.insert({s[i], i});
            }
            else
            {
                ans = max(ans, (int)m.size());
                auto it_next = m.begin();

                for (auto it = it_next; it != m.end(); it = it_next)
                {
                    it_next++;

                    if (it->second < m[s[i]])
                        m.erase(it->first);
                }

                m[s[i]] = i;
            }
        }

        ans = max(ans, (int)m.size());

        return ans;
    }
};

int main()
{

    Solution s;

    cout << s.lengthOfLongestSubstring("nfvbiywbasfbu");

    return 0;
}