/* ----------------------------------------------------- */
/* MaxAreaIsland.cpp                                     */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Max Area of Island */
/* Difficulty: Medium */

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int area = 0;

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == 1)
                {
                    int new_area = bfs(grid, r, c);
                    area = max(new_area, area);
                }
            }
        }

        return area;
    }

    int bfs(vector<vector<int>> &grid, int r, int c)
    {
        grid[r][c] = 0;
        queue<pair<int, int>> q;
        q.push({r, c});

        int area = 1;

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;

            for (int i = 0; i < 4; i++)
            {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];

                if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1)
                {
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                    area += 1;
                }
            }
        }
        return area;
    }
};