/* ----------------------------------------------------- */
/* LongestPalindromicSubstring.cpp                       */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Longest Palindromic Substring */
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

class TwoPointersSolution
{
public:
    string longestPalindrome(string s)
    {
        int size = s.length();

        int resLen = 0;
        int resIdx = 0;

        for (int i = 0; i < size; i++)
        {
            int l = i;
            int r = i;

            while (l >= 0 && r < size)
            {
                if (s[l] != s[r])
                {
                    break;
                }
                if (r - l + 1 > resLen)
                {
                    resLen = r - l + 1;
                    resIdx = l;
                }
                l--;
                r++;
            }
        }

        for (int i = 0; i < size - 1; i++)
        {
            int l = i;
            int r = i + 1;

            while (l >= 0 && r < size)
            {
                if (s[l] != s[r])
                {
                    break;
                }
                if (r - l + 1 > resLen)
                {
                    resLen = r - l + 1;
                    resIdx = l;
                }
                l--;
                r++;
            }
        }

        string ans = "";
        for (int i = resIdx; i < resIdx + resLen; i++)
        {
            ans.push_back(s[i]);
        }
        return ans;
    }
};

class DPSolution
{
public:
    string longestPalindrome(string s)
    {
        int size = s.length();
        vector<vector<bool>> palindrome(size, vector<bool>(size, false));

        int resLen = 0;
        int resIdx = 0;

        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = i; j < size; j++)
            {
                if (s[i] == s[j] && (j - i <= 2 || palindrome[i + 1][j - 1]))
                {
                    palindrome[i][j] = true;
                    if (j - i + 1 > resLen)
                    {
                        resLen = j - i + 1;
                        resIdx = i;
                    }
                }
            }
        }

        return s.substr(resIdx, resLen);
    }
};