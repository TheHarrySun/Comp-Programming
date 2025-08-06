/* ----------------------------------------------------- */
/* LongestIncreasingSubsequence.cpp                      */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Longest Increasing Subsequence */
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
    int lengthOfLIS(vector<int> &nums)
    {
        vector<vector<int>> memo(nums.size() + 1, vector<int>(nums.size(), -1));
        return dfs(nums, -1, 0, memo);
    }

    int dfs(vector<int> nums, int prev, int curr, vector<vector<int>> &memo)
    {
        if (curr == nums.size())
        {
            return 0;
        }

        int ans;

        if (memo[prev + 1][curr] == -1)
            ans = dfs(nums, prev, curr + 1, memo);
        else
            ans = memo[prev + 1][curr];

        if (prev == -1 || nums[prev] < nums[curr])
        {
            ans = max(ans, 1 + dfs(nums, curr, curr + 1, memo));
        }
        memo[prev + 1][curr] = ans;
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {9, 1, 4, 2, 3, 3, 7};
    cout << obj.lengthOfLIS(nums) << endl;
}