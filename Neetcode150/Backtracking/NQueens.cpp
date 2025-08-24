/* ----------------------------------------------------- */
/* NQueens.cpp                                           */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: N-Queens */
/* Difficulty: Hard */

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <limits>
#include <unordered_set>
#include <stack>
#include <set>
#include <string>

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;

        vector<string> board(n, string(n, '.'));
        backtrack(res, board, 0);
        return res;
    }

    void backtrack(vector<vector<string>> &res, vector<string> &board, int r)
    {
        if (r == board.size())
        {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < board.size(); c++)
        {
            if (isSafe(r, c, board))
            {
                board[r][c] = 'Q';
                backtrack(res, board, r + 1);
                board[r][c] = '.';
            }
        }
    }
    bool isSafe(int r, int c, vector<string> &board)
    {
        for (int i = 0; i < r; i++)
        {
            if (board[i][c] == 'Q')
            {
                return false;
            }
        }
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
};