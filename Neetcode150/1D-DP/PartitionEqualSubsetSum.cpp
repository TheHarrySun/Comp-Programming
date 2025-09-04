/* ----------------------------------------------------- */
/* PartitionEqualSubsetSum.cpp                           */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Partition Equal Subset Sum */
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
    vector<vector<int>> memo;
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        if (sum % 2 == 1)
        {
            return false;
        }
        int half = sum / 2;
        memo.resize(nums.size(), vector<int>(half + 1, -1));
        return dfs(nums, 0, half);
    }

    bool dfs(vector<int> &nums, int i, int half)
    {
        if (i == nums.size())
        {
            return half == 0;
        }
        if (half < 0)
        {
            return false;
        }
        if (memo[i][half] != -1)
        {
            return memo[i][half];
        }
        memo[i][half] = dfs(nums, i + 1, half) || dfs(nums, i + 1, half - nums[i]);
        return memo[i][half];
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 3, 4, 6, 7, 9};
    cout << obj.canPartition(nums) << endl;
}