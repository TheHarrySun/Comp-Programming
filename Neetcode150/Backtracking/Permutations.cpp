/* ----------------------------------------------------- */
/* Permutations.cpp                                      */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Permutations */
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
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> contained(nums.size(), false);
        dfs(curr, contained, nums, res);
        return res;
    }

private:
    void dfs(vector<int> &curr, vector<bool> contained, vector<int> &nums, vector<vector<int>> &res)
    {
        if (curr.size() == nums.size())
        {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!contained[i])
            {
                curr.push_back(nums[i]);
                contained[i] = true;
                dfs(curr, contained, nums, res);
                curr.pop_back();
                contained[i] = false;
            }
        }
    }
};