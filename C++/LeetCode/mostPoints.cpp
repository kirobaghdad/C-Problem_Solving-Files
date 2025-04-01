#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> ans;

    long long solve(vector<vector<int>> &questions, int i)
    {
        if (i >= questions.size())
            return 0;

        if (ans[i] != -1)
            return ans[i];

        return ans[i] = max(questions[i][0] + solve(questions, i + questions[i][1] + 1), solve(questions, i + 1));
    }

    long long mostPoints(vector<vector<int>> questions)
    {
        ans = vector<long long>(questions.size(), -1);
        solve(questions, 0);
        return ans[0];
    }
};

int main()
{
    Solution s;

    cout << s.mostPoints({{3, 2}, {4, 3}, {4, 4}, {2, 5}});
    return 0;
}