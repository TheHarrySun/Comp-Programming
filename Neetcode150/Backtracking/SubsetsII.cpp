/* ----------------------------------------------------- */
/* SubsetsII.cpp                                         */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Subsets II */
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
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        dfs(0, curr, nums, res);
        return res;
    }

private:
    void dfs(int index, vector<int> curr, vector<int> nums, vector<vector<int>> &res)
    {
        if (index == nums.size())
        {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        dfs(index + 1, curr, nums, res);
        curr.pop_back();
        while (index != nums.size() - 1 && nums[index] == nums[index + 1])
        {
            index++;
        }
        dfs(index + 1, curr, nums, res);
    }
};