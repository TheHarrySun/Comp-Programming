/* ----------------------------------------------------- */
/* Subsets.cpp                                           */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Subsets */
/* Difficulty: Medium */

#include <vector>

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> curr = {};
        dfs(res, 0, nums, curr);
        return res;
    }

private:
    void dfs(vector<vector<int>> &res, int index, vector<int> nums, vector<int> &curr)
    {
        if (index == nums.size())
        {
            res.push_back(curr);
            return;
        }
        vector<int> temp(curr);
        dfs(res, index + 1, nums, temp);
        curr.push_back(nums[index]);
        dfs(res, index + 1, nums, curr);
    }
};