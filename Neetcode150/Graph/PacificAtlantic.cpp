/* ----------------------------------------------------- */
/* PacificAtlantic.cpp                                   */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Pacific Atlantic Water Flow */
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
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        queue<pair<int, int>> pacq, atlq;

        for (int i = 0; i < rows; i++)
        {
            pacq.push({i, 0});
            atlq.push({i, cols - 1});
        }
        for (int i = 0; i < cols; i++)
        {
            pacq.push({0, i});
            atlq.push({rows - 1, i});
        }

        bfs(pacific, pacq, heights);
        bfs(atlantic, atlq, heights);

        vector<vector<int>> ans;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

private:
    void bfs(vector<vector<bool>> &ocean, queue<pair<int, int>> &q, vector<vector<int>> &heights)
    {
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            ocean[r][c] = true;
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];

                if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c])
                {
                    q.push({nr, nc});
                }
            }
        }
    }
};