/* ----------------------------------------------------- */
/* BuyandSellStock.cpp                                   */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Best Time to Buy and Sell Stock */
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
    int maxProfit(vector<int> &prices)
    {
        int smallest = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            ans = max(prices[i] - smallest, ans);
            if (prices[i] < smallest)
            {
                smallest = prices[i];
            }
        }
        return ans;
    }
};
