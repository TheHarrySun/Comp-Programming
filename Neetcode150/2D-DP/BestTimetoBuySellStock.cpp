/* ----------------------------------------------------- */
/* BestTimetoBuySellStock.cpp                            */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Best Time to Buy and Sell Stock with Cooldown */
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

// Brute force solution: do recursion with all the possible circumstances
// At each step, you either buy or sell.
class BruteForceSolution
{
public:
    int maxProfit(vector<int> &prices)
    {
        return dfs(0, true, prices);
    }

private:
    int dfs(int i, bool buying, vector<int> &prices)
    {
        if (i >= prices.size())
        {
            return 0;
        }

        int cooldown = dfs(i + 1, buying, prices);
        if (buying)
        {
            int buy = dfs(i + 1, false, prices) - prices[i];
            return max(buy, cooldown);
        }
        else
        {
            int sell = dfs(i + 2, true, prices) + prices[i];
            return max(sell, cooldown);
        }
    }
};

// DFS solution: basically the same as the brute force solution except
// we keep track of the value of each dfs so as to avoid re-calculating stuff
class DPSolution
{
public:
    unordered_map<string, int> dp;

    int maxProfit(vector<int> &prices)
    {
        return dfs(0, true, prices);
    }

private:
    int dfs(int i, bool buying, vector<int> &prices)
    {
        if (i >= prices.size())
        {
            return 0;
        }

        string key = to_string(i) + "-" + to_string(buying);

        if (dp.find(key) != dp.end())
        {
            return dp[key];
        }
        int cooldown = dfs(i + 1, buying, prices);
        if (buying)
        {
            int buy = dfs(i + 1, false, prices) - prices[i];
            dp[key] = max(buy, cooldown);
            return dp[key];
        }
        else
        {
            int sell = dfs(i + 2, true, prices) + prices[i];
            dp[key] = max(sell, cooldown);
            return dp[key];
        }
    }
};