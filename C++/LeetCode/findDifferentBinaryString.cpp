#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findDifferentBinaryString(vector<string> nums)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        // convert to int

        set<int> n;
        int base, temp;

        for (int i = 0; i < nums.size(); i++)
        {
            base = 1;
            temp = 0;
            for (int j = nums[i].size() - 1; j >= 0; j--)
            {
                temp += (nums[i][j] - '0') * base;
                base *= 2;
            }
            n.insert(temp);
        }

        string ans;
        for (int i = 0; i <= pow(nums[0].size(), 2); i++)
        {
            if (n.find(i) == n.end())
            {
                // convert to binary

                while (i)
                {
                    ans = to_string(i % 2) + ans;
                    i = i / 2;
                }

                while (ans.size() != nums[i].size())
                {
                    ans = '0' + ans;
                }

                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.findDifferentBinaryString({"00", "10"});

    return 0;
}