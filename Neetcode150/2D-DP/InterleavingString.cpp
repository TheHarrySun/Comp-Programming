/* ----------------------------------------------------- */
/* InterleavingString.cpp                                */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Interleaving String */
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
    vector<vector<int>> dp;
    bool isInterleave(string s1, string s2, string s3)
    {
        dp = vector<vector<int>>(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return dfs(s1, s2, s3, 0, 0);
    }

    bool dfs(string s1, string s2, string s3, int p1, int p2)
    {
        if (dp[p1][p2] != -1)
        {
            return dp[p1][p2];
        }
        int p3 = p1 + p2;
        if (p1 == s1.length())
        {
            return s2.substr(p2) == s3.substr(p3);
        }
        if (p2 == s2.length())
        {
            return s1.substr(p1) == s3.substr(p3);
        }
        if (s1[p1] == s3[p3] && s2[p2] == s3[p3])
        {
            dp[p1][p2] = dfs(s1, s2, s3, p1 + 1, p2) || dfs(s1, s2, s3, p1, p2 + 1);
        }
        else if (s1[p1] == s3[p3])
        {
            dp[p1][p2] = dfs(s1, s2, s3, p1 + 1, p2);
        }
        else if (s2[p2] == s3[p3])
        {
            dp[p1][p2] = dfs(s1, s2, s3, p1, p2 + 1);
        }
        else
        {
            dp[p1][p2] = false;
        }
        return dp[p1][p2];
    }
};

int main()
{
    Solution obj;
    string s1 = "aaaa";
    string s2 = "bbbb";
    string s3 = "aabbbbaa";
    cout << obj.isInterleave(s1, s2, s3) << endl;
}