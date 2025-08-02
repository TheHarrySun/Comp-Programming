/* ----------------------------------------------------- */
/* IslandsTreasure.cpp                                   */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Islands and Treasure */
/* Difficulty: Medium */

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
    unsigned int land = numeric_limits<int>::max();
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    void islandsAndTreasure(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] != land)
                {
                    continue;
                }
                grid[nr][nc] = grid[row][col] + 1;
                q.push({nr, nc});
            }
        }
    }
};
