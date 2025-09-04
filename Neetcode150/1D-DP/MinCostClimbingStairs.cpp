/* ----------------------------------------------------- */
/* MinCostClimbingStairs.cpp                             */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Minimum Cost Climbing Stairs */
/* Difficulty: Easy */

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
    int minCostClimbingStairs(vector<int> &cost)
    {
        int num_stairs = cost.size();
        int totalCosts[num_stairs];
        totalCosts[num_stairs - 1] = cost[num_stairs - 1];
        totalCosts[num_stairs - 2] = cost[num_stairs - 2];

        for (int i = num_stairs - 3; i >= 0; i--)
        {
            totalCosts[i] = min(totalCosts[i + 1] + cost[i], totalCosts[i + 2] + cost[i]);
        }
        return min(totalCosts[0], totalCosts[1]);
    }
};