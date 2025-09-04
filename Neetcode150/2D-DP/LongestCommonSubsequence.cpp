/* ----------------------------------------------------- */
/* LongestCommonSubsequence.cpp                          */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Longest Common Subsequence */
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
    int longestCommonSubsequence(string text1, string text2)
    {
        int length1 = text1.length();
        int length2 = text2.length();

        vector<vector<int>> dp(length1, vector<int>(length2, -1));

        return dfs(text1, text2, 0, 0, dp);
    }

    int dfs(string text1, string text2, int index1, int index2, vector<vector<int>> &dp)
    {
        if (index1 == text1.length() || index2 == text2.length())
        {
            return 0;
        }
        if (dp[index1][index2] != -1)
        {
            return dp[index1][index2];
        }
        if (text1[index1] == text2[index2])
        {
            int ans = 1 + dfs(text1, text2, index1 + 1, index2 + 1, dp);
            dp[index1][index2] = ans;
            return ans;
        }
        int ans = max(dfs(text1, text2, index1 + 1, index2, dp), dfs(text1, text2, index1, index2 + 1, dp));
        dp[index1][index2] = ans;
        return ans;
    }
};