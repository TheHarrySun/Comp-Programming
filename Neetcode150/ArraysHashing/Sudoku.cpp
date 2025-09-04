/* ----------------------------------------------------- */
/* Sudoku.cpp                                            */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Valid Sudoku */
/* Difficulty: Medium */

#include <vector>
#include <unordered_set>

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int n = 9;
        for (int i = 0; i < n; i++)
        {
            unordered_set<char> seth;
            unordered_set<char> setv;
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != '.' && (seth.count(board[i][j]) == 1))
                {
                    return false;
                }
                if (board[j][i] != '.' && (setv.count(board[j][i]) == 1))
                {
                    return false;
                }
                seth.insert(board[i][j]);
                setv.insert(board[j][i]);
            }
            int firstx = 3 * (i % 3);
            int firsty = 3 * (i / 3);
            unordered_set<char> setsq;
            for (int j = firstx; j < firstx + 3; j++)
            {
                for (int k = firsty; k < firsty + 3; k++)
                {
                    if (board[j][k] == '.')
                    {
                        continue;
                    }
                    if (setsq.count(board[j][k]) == 1)
                    {
                        return false;
                    }
                    setsq.insert(board[j][k]);
                }
            }
        }
        return true;
    }
};
