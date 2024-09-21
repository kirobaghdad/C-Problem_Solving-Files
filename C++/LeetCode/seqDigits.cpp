#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        int l = to_string(low).size();
        int h = to_string(high).size();

        vector<int> ans;

        string s;

        for (int i = 1; i < 10; i++)
            s += to_string(i);

        for (int i = l; i <= h; i++)
        {

            for (int j = 0; j < 10 - i; j++)
            {
                int temp = stoi(s.substr(j, i));

                if (temp >= low && temp <= high)
                    ans.push_back(temp);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> ans = s.sequentialDigits(1000, 13000);

    for (auto it : ans)
        cout << it << " ";
    return 0;
}