/* ----------------------------------------------------- */
/* WordBreak.cpp                                         */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Word Break */
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
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (string word : wordDict)
            {
                if (dp[i] == true)
                {
                    continue;
                }
                if (i + word.size() <= s.size() && s.substr(i, word.size()) == word)
                {
                    dp[i] = dp[i + word.size()];
                }
            }
        }
        return dp[0];
    }
};

int main()
{
    Solution obj;
    string s = "abcd";
    vector<string> wordDict = {"a", "b", "abc", "cd"};
    cout << obj.wordBreak(s, wordDict) << endl;
}