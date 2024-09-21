#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {

        vector<char> stack;
        string ans;

        for (int i = 0; i < num.size(); i++)
        {
            while (k > 0 && !stack.empty() && stack.back() > num[i])
            {
                stack.pop_back();
                k--;
            }

            stack.push_back(num[i]);
        }

        while (k-- > 0)
            stack.pop_back();

        for (auto c : stack)
            ans += c;

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.removeKdigits("10200", 1);

    return 0;
}