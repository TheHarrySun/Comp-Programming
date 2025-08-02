/* ----------------------------------------------------- */
/* RottingFruit.cpp                                      */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Rotting Fruit */
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
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;

        int rows = grid.size();
        int cols = grid[0].size();

        int fresh = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                if (grid[i][j] == 1)
                {
                    fresh += 1;
                }
            }
        }
        int time = 0;
        while (fresh > 0 && !q.empty())
        {
            int length = q.size();
            for (int i = 0; i < length; i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int j = 0; j < 4; j++)
                {
                    int nr = row + dirs[j][0];
                    int nc = col + dirs[j][1];
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    {
                        continue;
                    }
                    if (grid[nr][nc] == 1)
                    {
                        q.push({nr, nc});
                        grid[nr][nc] = 2;
                        fresh -= 1;
                    }
                }
            }
            time += 1;
        }
        if (fresh != 0)
        {
            return -1;
        }

        return time;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> grid;
    grid.push_back({2});
    grid.push_back({1});
    cout << obj.orangesRotting(grid) << endl;
}