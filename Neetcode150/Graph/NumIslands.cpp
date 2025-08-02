/* ----------------------------------------------------- */
/* NumIslands.cpp                                        */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Number of Islands */
/* Difficulty: Medium */

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0)
        {
            return 0;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == '1')
                {
                    bfs(grid, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }

    void bfs(vector<vector<char>> &grid, int r, int c)
    {
        queue<pair<int, int>> q;
        grid[r][c] = '0';
        q.push({r, c});

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;
            for (int i = 0; i < 4; i++)
            {
                int new_row = row + directions[i][0];
                int new_col = col + directions[i][1];
                if (new_row >= 0 && new_row < grid.size() && new_col >= 0 && new_col < grid[0].size() && grid[new_row][new_col] == '1')
                {
                    q.push({new_row, new_col});
                    grid[new_row][new_col] = '0';
                }
            }
        }
    }
};