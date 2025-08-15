/* ----------------------------------------------------- */
/* TargetSum.cpp                                         */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Target Sum */
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

// Brute force solution is simple; at each time step, consider if you add or subtract
class BruteForceSolution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return dfs(0, 0, nums, target);
    }

private:
    int dfs(int index, int total, vector<int> &nums, int target)
    {
        if (index == nums.size() && total == target)
        {
            return 1;
        }
        else if (index == nums.size())
        {
            return 0;
        }
        return dfs(index + 1, total - nums[index], nums, target) + dfs(index + 1, total + nums[index], nums, target);
    }
};

/* ----------------------------------------------------- */

// DP solution is basically the same but do a memoization thing: keep track of the total and the index
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }

        vector<vector<int>> dp(nums.size() + 1, vector<int>(2 * sum + 1, -1));
        return dfs(0, 0, nums, target, dp, sum);
    }

private:
    int dfs(int index, int total, vector<int> &nums, int target, vector<vector<int>> &dp, int sum)
    {
        int temp = total + sum;
        if (index == nums.size() && total == target)
        {
            dp[index][temp] = 1;
            return 1;
        }
        else if (index == nums.size())
        {
            dp[index][temp] = 0;
            return 0;
        }
        if (dp[index][temp] != -1)
        {
            return dp[index][temp];
        }

        int ans = dfs(index + 1, total - nums[index], nums, target, dp, sum) + dfs(index + 1, total + nums[index], nums, target, dp, sum);
        dp[index][temp] = ans;
        return ans;
    }
};

int main()
{
    Solution obj;
    int target = 2;
    vector<int> nums = {2, 2, 2};
    cout << obj.findTargetSumWays(nums, target) << endl;
}