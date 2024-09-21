#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // i -> Row, j -> Column

    vector<vector<int>> uniquePath;

    int unique(int m, int n, int i = 0, int j = 0)
    {
        if (i >= m || j >= n)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        int temp;

        if (uniquePath[i][j] == -1)
        {
            uniquePath[i][j] = unique(m, n, i + 1, j) + unique(m, n, i, j + 1);
        }

        return uniquePath[i][j];
    }

    int uniquePaths(int m, int n)
    {
        uniquePath = vector<vector<int>>(m, vector<int>(n, -1));

        return unique(m, n);
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(19, 13);

    return 0;
}