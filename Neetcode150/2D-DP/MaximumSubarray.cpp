/* ----------------------------------------------------- */
/* MaximumSubarray.cpp                                   */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Maximum Subarray */
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
    int maxSubArray(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2, INT_MIN));
        return dfs(0, nums, false, dp);
    }

private:
    int dfs(int index, vector<int> nums, bool flag, vector<vector<int>> &dp)
    {
        if (index == nums.size())
        {
            return flag ? 0 : INT_MIN;
        }
        int i = flag ? 1 : 0;
        if (dp[index][i] != INT_MIN)
        {
            return dp[index][i];
        }
        if (flag)
        {
            dp[index][i] = max(0, nums[index] + dfs(index + 1, nums, flag, dp));
        }
        else
        {
            dp[index][i] = max(dfs(index + 1, nums, flag, dp), nums[index] + dfs(index + 1, nums, true, dp));
        }
        return dp[index][i];
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {2, -3, 4, -2, 2, 1, -1, 4};
    cout << obj.maxSubArray(nums) << endl;
}