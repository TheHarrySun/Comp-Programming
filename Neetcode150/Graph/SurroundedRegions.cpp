/* ----------------------------------------------------- */
/* SurroundedRegions.cpp                                 */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Surrounded Regions */
/* Difficulty: Medium */

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <limits>
#include <unordered_set>

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if ((i == 0 || j == 0 || i == rows - 1 || j == cols - 1) && board[i][j] == 'O')
                {
                    q.push({i, j});
                }
            }
        }

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            board[row][col] = '#';
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];

                if (nr >= 0 && nr < rows && nc >= 0 & nc < cols && board[nr][nc] == 'O')
                {
                    q.push({nr, nc});
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
                else
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};