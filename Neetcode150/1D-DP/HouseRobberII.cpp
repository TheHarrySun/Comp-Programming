/* ----------------------------------------------------- */
/* HouseRobberII.cpp                                     */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: House Robber II */
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

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1)
        {
            return nums[0];
        }
        int minus_first[size - 1];
        int minus_last[size - 1];

        /* minus_first house */
        minus_first[0] = nums[1];
        minus_first[1] = max(nums[1], nums[2]);
        for (int i = 2; i < size - 1; i++)
        {
            minus_first[i] = max(minus_first[i - 1], minus_first[i - 2] + nums[i + 1]);
        }

        /* minus_last house */
        minus_last[0] = nums[0];
        minus_last[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size - 1; i++)
        {
            minus_last[i] = max(minus_last[i - 1], minus_last[i - 2] + nums[i]);
        }

        return max(minus_last[size - 2], minus_first[size - 2]);
    }
};