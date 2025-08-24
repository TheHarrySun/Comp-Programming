/* ----------------------------------------------------- */
/* MinimumWindowSubstring.cpp                            */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Minimum Window Substring */
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
    string minWindow(string s, string t)
    {
        if (t == "")
        {
            return "";
        }
        unordered_map<char, int> countT;

        for (char c : t)
        {
            countT[c] += 1;
        }

        unordered_map<char, int> window;

        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;
        for (int r = 0; r < s.length(); r++)
        {
            char c = s[r];
            if (countT.find(c) != countT.end())
            {
                window[c] += 1;
            }
            if (countT.count(c) && window[c] == countT[c])
            {
                have++;
            }
            while (have == need)
            {
                if (resLen > r - l + 1)
                {
                    resLen = r - l + 1;
                    res = {l, r};
                }
                if (countT.find(s[l]) != countT.end())
                {
                    window[s[l]] -= 1;
                }
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]])
                {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, res.second + 1 - res.first);
    }
};