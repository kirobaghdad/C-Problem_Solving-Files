#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> temps)
    {
        std::vector<int> results(temps.size());
        std::stack<int> stack;
        /// UPVOTE !
        for (int i = 0; i < temps.size(); i++)
        {
            while (!stack.empty() && temps[stack.top()] < temps[i])
            {
                results[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }

        return results;
    }
};

int main()
{
    Solution s;

    s.dailyTemperatures({73, 74, 75, 71, 69, 72, 76, 73});

    return 0;
}