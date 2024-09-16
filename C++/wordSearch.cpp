#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<bool>> isVisited;

    bool solve(vector<vector<char>> &board, string &word, int i = 0, int arrIndex = 0)
    {
        if (arrIndex == board.size() * board[0].size())
            return false;

        int row = arrIndex / board[0].size();
        int col = arrIndex % board[0].size();

        bool temp = false;

        if (board[row][col] == word[i])
        {
            isVisited[row][col] = true;
            if (i == word.size() - 1)
                return true;

            if (col + 1 < board[0].size() && !isVisited[row][col + 1] && board[row][col + 1] == word[i + 1])
            {
                isVisited[row][col + 1] = 1;
                temp |= solve(board, word, i + 1, arrIndex + 1);
                isVisited[row][col + 1] = 0;
            }

            if (col - 1 >= 0 && !isVisited[row][col - 1] && board[row][col - 1] == word[i + 1])
            {
                isVisited[row][col - 1] = 1;
                temp |= solve(board, word, i + 1, arrIndex - 1);
                isVisited[row][col - 1] = 0;
            }

            if (row - 1 >= 0 && !isVisited[row - 1][col] && board[row - 1][col] == word[i + 1])
            {
                isVisited[row - 1][col] = 1;
                temp |= solve(board, word, i + 1, arrIndex - board[0].size());
                isVisited[row - 1][col] = 0;
            }

            if (row + 1 < board.size() && !isVisited[row + 1][col] && board[row + 1][col] == word[i + 1])
            {
                isVisited[row + 1][col] = 1;
                temp |= solve(board, word, i + 1, arrIndex + board[0].size());
                isVisited[row + 1][col] = 0;
            }

            isVisited[row][col] = false;

            if (!temp && i)
                return false;
        }

        return temp || solve(board, word, i, arrIndex + 1);
    }

    bool exist(vector<vector<char>> board, string word)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        isVisited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

        return solve(board, word);
    }
};

int main()
{
    Solution s;
    // vector<vector<char>> t = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    vector<vector<char>> t = {{'a', 'a'}};

    cout
        << s.exist(t, "aaa");

    return 0;
}