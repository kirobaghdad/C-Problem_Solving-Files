#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        string temp;

        for (char c : s)
        {
            if (temp.size() && abs(temp.back() - c) == 32)
                temp.pop_back();
            else
                temp.push_back(c);
        }

        return temp;

        // stack<char> right;
        // stack<char> left;

        // for (auto i : s)
        //     left.push(i);

        // while (left.size())
        // {

        //     if (right.size() && abs(int(left.top()) - int(right.top())) == 32)
        //     {
        //         right.pop();
        //         left.pop();
        //     }
        //     else
        //     {
        //         char temp = left.top();
        //         left.pop();
        //         right.push(temp);
        //     }
        // }

        // s = "";

        // while (right.size())
        // {
        //     s += right.top();
        //     right.pop();
        // }

        // return s;
    }
};
int main()
{

    Solution s;

    cout << s.makeGood("leEeetcode");

    return 0;
}