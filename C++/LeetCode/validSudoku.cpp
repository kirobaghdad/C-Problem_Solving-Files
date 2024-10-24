#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> board)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<set<char>> cols(9, set<char>());
        set<char> row;
        vector<set<char>> grids(9, set<char>());

        for (int i = 0; i < board.size(); i++)
        {
            row.clear();

            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] != '.')
                {
                    if (row.count(board[i][j]))
                    {
                        return false;
                    }

                    int gridNum = j / 3 + ((i / 3) * 3);

                    if (grids[gridNum].find(board[i][j]) != grids[gridNum].end())
                        return false;

                    if (cols[j].find(board[i][j]) != cols[j].end())
                        return false;

                    row.insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    grids[gridNum].insert(board[i][j]);
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution s;

    cout << s.isValidSudoku({{'.', '.', '.', '.', '5', '.', '.', '1', '.'}, {'.', '4', '.', '3', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '3', '.', '.', '1'}, {'8', '.', '.', '.', '.', '.', '.', '2', '.'}, {'.', '.', '2', '.', '7', '.', '.', '.', '.'}, {'.', '1', '5', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '2', '.', '.', '.'}, {'.', '2', '.', '9', '.', '.', '.', '.', '.'}, {'.', '.', '4', '.', '.', '.', '.', '.', '.'}});

    return 0;
}
