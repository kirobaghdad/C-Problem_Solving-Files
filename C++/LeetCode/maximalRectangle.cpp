#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> matrix)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int ans = 0;

        vector<int> temp(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] - '0')
                    temp[j] = temp[j] + matrix[i][j] - '0';
                else
                    temp[j] = 0;

                ans = max(ans, temp[j]);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.maximalRectangle({{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}});

    return 0;
}