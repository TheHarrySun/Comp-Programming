/* ----------------------------------------------------- */
/* WordSearch.cpp                                        */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Palindrome Partitioning */
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
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> curr;
        dfs(s, 0, 0, curr, res);
        return res;
    }

private:
    void dfs(string s, int i, int j, vector<string> curr, vector<vector<string>> &res)
    {
        if (j == s.length())
        {
            res.push_back(curr);
            return;
        }
        string partition = s.substr(i, j - i + 1);
        if (checkPalindrome(partition))
        {
            curr.push_back(partition);
            dfs(s, j + 1, j + 1, curr, res);
            curr.pop_back();
            if (j + 1 != s.length())
            {
                dfs(s, i, j + 1, curr, res);
            }
        }
        else
        {
            if (j + 1 == s.length())
            {
                return;
            }
            dfs(s, i, j + 1, curr, res);
        }
    }

    bool checkPalindrome(string s)
    {
        int p1 = 0;
        int p2 = s.length() - 1;
        while (p1 < p2)
        {
            if (s[p1] == s[p2])
            {
                p1++;
                p2--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution obj;
    string s = "aab";
    vector<vector<string>> ans = obj.partition(s);
    for (auto it : ans)
    {
        for (string x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}