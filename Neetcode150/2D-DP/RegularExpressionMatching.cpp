/* ----------------------------------------------------- */
/* RegularExpressionMatching.cpp                         */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Regular Expression Matching */
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
    bool isMatch(string s, string p)
    {
        dp = vector<vector<int>>(s.length() + 1, vector<int>(p.length() + 1, -1));
        return dfs(0, 0, s, p);
    }

    bool dfs(int index1, int index2, string s, string p)
    {
        if (dp[index1][index2] != -1)
        {
            return dp[index1][index2];
        }
        if (index1 == s.length() && index2 == p.length())
        {
            return true;
        }
        else if (index1 == s.length() && ((index2 == p.length() - 1 || index2 == p.length() - 2) && p[p.length() - 1] == '*'))
        {
            return true;
        }
        else if (index1 == s.length() || index2 == p.length())
        {
            return false;
        }

        bool ans = false;
        if (s[index1] == p[index2] || p[index2] == '.')
        {
            ans = dfs(index1 + 1, index2 + 1, s, p);
        }
        else if (p[index2] == '*')
        {
            if (p[index2 - 1] == s[index1] || p[index2 - 1] == '.')
            {
                ans = ans || dfs(index1 + 1, index2, s, p) || dfs(index1, index2 + 1, s, p);
            }
            else
            {
                ans = ans || dfs(index1, index2 + 1, s, p);
            }
        }
        if (index2 < p.length() - 1 && p[index2 + 1] == '*')
        {
            ans = ans || dfs(index1, index2 + 2, s, p);
        }
        dp[index1][index2] = ans;
        return ans;
    }
};

int main()
{
    Solution obj;
    string s = "bbbbba";
    string p = ".*a*a";
    cout << obj.isMatch(s, p) << endl;
}