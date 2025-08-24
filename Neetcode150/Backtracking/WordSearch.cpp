/* ----------------------------------------------------- */
/* WordSearch.cpp                                        */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Word Search */
/* Difficulty: Medium */

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
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, visited, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>> board, string word, vector<vector<bool>> visited, int i, int j, int word_idx)
    {
        word_idx++;
        if (word_idx == word.size())
        {
            return true;
        }
        visited[i][j] = true;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        bool ans = false;
        for (auto dir : dirs)
        {
            int row = i + dir[0];
            int col = j + dir[1];
            if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && board[row][col] == word[word_idx] && !visited[row][col])
            {
                ans = ans || dfs(board, word, visited, row, col, word_idx);
            }
        }
        visited[i][j] = false;
        return ans;
    }
};