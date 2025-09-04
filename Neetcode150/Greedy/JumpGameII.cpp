/* ----------------------------------------------------- */
/* JumpGameII.cpp                                        */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Jump Game II */
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

/* DP solution is O(n^2), so it's not efficient enough. */
class DPSolution
{
public:
    int jump(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> dp(size, 1e6);

        dp[size - 1] = 0;
        for (int i = size - 2; i >= 0; i--)
        {
            int end = min(i + nums[i], size - 1);
            for (int j = i + 1; j <= end; j++)
            {
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
        return dp[0];
    }
};

/* Greedy solution is O(n). */
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int res = 0, l = 0, r = 0;

        while (r < nums.size() - 1)
        {
            int farthest = 0;
            for (int i = l; i <= r; i++)
            {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            res++;
        }
        return res;
    }
};