/* ----------------------------------------------------- */
/* LongestIncreasingPathinMatrix.cpp                     */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Longest Increasing Path in Matrix */
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
    vector<vector<int>> dp;
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int lowest = numeric_limits<int>::min();
        int rows = matrix.size();
        int cols = matrix[0].size();
        dp = vector<vector<int>>(rows, vector<int>(cols, -1));

        int ans = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                ans = max(ans, dfs(lowest, i, j, matrix));
            }
        }

        return ans;
    }

private:
    int dfs(int prev, int row, int col, vector<vector<int>> matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        if (row == rows || row == -1 || col == cols || col == -1)
        {
            return 0;
        }

        int curr = matrix[row][col];

        if (prev < matrix[row][col])
        {
            if (dp[row][col] != -1)
            {
                return dp[row][col];
            }
            int ans = 1 + max(dfs(curr, row + 1, col, matrix), max(dfs(curr, row - 1, col, matrix), max(dfs(curr, row, col + 1, matrix), dfs(curr, row, col - 1, matrix))));
            dp[row][col] = ans;
            return ans;
        }
        return 0;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> matrix;
    matrix.push_back({5, 5, 3});
    matrix.push_back({2, 3, 6});
    matrix.push_back({1, 1, 1});
    cout << obj.longestIncreasingPath(matrix) << endl;
}