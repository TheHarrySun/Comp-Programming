/* ----------------------------------------------------- */
/* ClimbingStairs.cpp                                    */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Climbing Stairs */
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
    int climbStairs(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        int ways[n];
        ways[n - 1] = 1;
        ways[n - 2] = 2;
        for (int i = n - 3; i >= 0; i--)
        {
            ways[i] = ways[i + 1] + ways[i + 2];
        }
        return ways[0];
    }
};