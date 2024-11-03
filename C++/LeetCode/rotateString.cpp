#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if (s.size() != goal.size())
            return false;

        return (s + s).find(goal) != string::npos;
    }
};

int main()
{

    return 0;
}