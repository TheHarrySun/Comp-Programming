/* ----------------------------------------------------- */
/* PalindromicSubstrings.cpp                             */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Palindromic Substrings */
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

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
public:
    int countSubstrings(string s)
    {
        int ans = 0;
        int size = s.length();
        vector<vector<bool>> dp(size, vector<bool>(size, false));

        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = i; j < size; j++)
            {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]))
                {
                    ans += 1;
                    dp[i][j] = true;
                }
            }
        }
        return ans;
    }
};