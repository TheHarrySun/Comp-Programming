/* ----------------------------------------------------- */
/* LetterCombinationsOfAPhoneNumber.cpp                  */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Letter Combinations of a Phone Number */
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
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, vector<char>> map;
        map['2'] = {'a', 'b', 'c'};
        map['3'] = {'d', 'e', 'f'};
        map['4'] = {'g', 'h', 'i'};
        map['5'] = {'j', 'k', 'l'};
        map['6'] = {'m', 'n', 'o'};
        map['7'] = {'p', 'q', 'r', 's'};
        map['8'] = {'t', 'u', 'v'};
        map['9'] = {'w', 'x', 'y', 'z'};

        vector<string> res;

        if (digits.length() == 0)
        {
            return res;
        }
        dfs(0, res, "", digits, map);
        return res;
    }

private:
    void dfs(int index, vector<string> &res, string curr, string digits, unordered_map<char, vector<char>> map)
    {
        if (curr.length() == digits.length())
        {
            res.push_back(curr);
        }

        for (char c : map[digits[index]])
        {
            curr.push_back(c);
            dfs(index + 1, res, curr, digits, map);
            curr.pop_back();
        }
    }
};

int main()
{
    Solution obj;
    string digits = "34";
    for (string s : obj.letterCombinations(digits))
    {
        cout << s << " ";
    }
    cout << endl;
}