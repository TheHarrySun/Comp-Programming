/* ----------------------------------------------------- */
/* JumpGame.cpp                                          */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Jump Game */
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

/* DP solution that is not the most efficient. */
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1)
        {
            return true;
        }
        vector<bool> dp(size, false);
        dp[size - 1] = true;
        for (int i = size - 2; i >= 0; i--)
        {
            for (int j = i; j <= i + nums[i]; j++)
            {
                if (dp[j] == true || j >= size)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};

/* More efficient solution is the greedy solution. */
class GreedySolution
{
public:
    bool canJump(vector<int> &nums)
    {
        int goal = nums.size() - 1;
        for (int i = goal - 1; i >= 0; i--)
        {
            if (i + nums[i] >= goal)
            {
                goal = i;
            }
        }
        return goal == 0;
    }
};

int main()
{
    vector<int> nums = {1, 2, 1, 0, 1};
    Solution obj;
    cout << obj.canJump(nums) << endl;
}