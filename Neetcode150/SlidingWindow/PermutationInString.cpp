/* ----------------------------------------------------- */
/* PermutationInString.cpp                   */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Permutation In String */
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
    bool checkInclusion(string s1, string s2)
    {
        vector<int> string1(26, 0);
        vector<int> string2(26, 0);
        for (char c : s1)
        {
            string1[c - 'a'] += 1;
        }
        if (s2.length() < s1.length())
        {
            return false;
        }
        int l = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            string2[s2[i] - 'a'] += 1;
        }
        int match = 0;
        for (int i = 0; i < 26; i++)
        {
            if (string1[i] == string2[i])
            {
                match += 1;
            }
        }
        for (int i = s1.length(); i < s2.length(); i++)
        {
            if (match == 26)
            {
                return true;
            }
            int index = s2[i] - 'a';
            string2[index] += 1;
            if (string2[index] == string1[index])
            {
                match += 1;
            }
            else if (string2[index] - 1 == string1[index])
            {
                match -= 1;
            }

            index = s2[l] - 'a';
            string2[index] -= 1;
            if (string2[index] == string1[index])
            {
                match += 1;
            }
            else if (string2[index] + 1 == string1[index])
            {
                match -= 1;
            }

            l++;
        }
        return match == 26;
    }
};
