#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        string ans;
        string temp;

        stringstream ss(s);

        while (ss >> temp)
        {
            temp += " ";
            ans.insert(0, temp);
        }

        ans.erase(ans.end() - 1);

        return ans;
    }
};

int main()
{
    Solution solution;

    cout << solution.reverseWords("the sky is blue");

    return 0;
}