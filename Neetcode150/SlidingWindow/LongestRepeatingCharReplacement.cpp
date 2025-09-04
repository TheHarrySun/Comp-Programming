/* ----------------------------------------------------- */
/* LongestRepeatingCharReplacement.cpp                   */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Longest Repeating Character Replacement */
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
    int characterReplacement(string s, int k)
    {
        if (s.length() == 0)
        {
            return 0;
        }
        unordered_map<char, int> freq;
        int first = 0;
        char max_key = s[0];
        int maxlength = 0;
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i]] += 1;
            if (freq[s[i]] > freq[max_key])
            {
                max_key = s[i];
            }

            while (i - first + 1 - freq[max_key] > k)
            {
                freq[s[first]]--;
                first += 1;
                for (auto pair : freq)
                {
                    if (pair.second > freq[max_key])
                    {
                        max_key = pair.first;
                    }
                }
            }
            maxlength = max(i - first + 1, maxlength);
        }
        return maxlength;
    }
};
