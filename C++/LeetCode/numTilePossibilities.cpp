#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<string> s;

    void solve(multiset<char> letters, string prev = "")
    {
        s.insert(prev);
        if (!letters.size())
        {
            return;
        }

        // take char only
        multiset<char> temp;

        for (auto it = letters.begin(); it != letters.end(); it++)
        {
            temp = letters;
            temp.erase(temp.find(*it));

            if (s.find(prev + *it) == s.end())
                solve(temp, prev + *it);

            if (s.find(*it + prev) == s.end())
                solve(temp, *it + prev);
        }
    }

    int numTilePossibilities(string tiles)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        multiset<char> letters;

        for (int i = 0; i < tiles.size(); i++)
            letters.insert(tiles[i]);

        solve(letters);

        return s.size() - 1;
    }
};
int main()
{
    Solution s;

    cout << s.numTilePossibilities("MGBENBK");

    return 0;
}