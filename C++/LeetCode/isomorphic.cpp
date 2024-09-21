#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     bool isIsomorphic(string s, string t)
//     {
//         ios::sync_with_stdio(false);
//         cin.tie(nullptr);
//         cout.tie(nullptr);
//         map<char, char> m;
//         set<char> c;

//         for (int i = 0; i < s.size(); i++)
//         {
//             if (m.find(s[i]) != m.end())
//             {
//                 if (t[i] != m[s[i]])
//                     return false;
//             }
//             else if (c.find(t[i]) != c.end())
//                 return false;

//             m[s[i]] = t[i];
//             c.insert(t[i]);
//         }
//         return true;
//     }
// };

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        char m1[260] = {0}, m2[260] = {0};
        for (int i = 0; i < s.size(); ++i)
        {
            if (m1[s[i]] != m2[t[i]])
                return false;
            m1[s[i]] = m2[t[i]] = i + 1;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isIsomorphic("egg", "add");
    return 0;
}