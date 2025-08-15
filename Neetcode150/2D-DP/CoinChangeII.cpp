/* ----------------------------------------------------- */
/* CoinChangeII.cpp                                      */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Coin Change II */
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

// Brute force solution: go through all recursion methods
class BruteForceSolution
{
public:
    int change(int amount, vector<int> &coins)
    {
        sort(coins.begin(), coins.end());
        return dfs(coins, 0, amount);
    }

private:
    int dfs(const vector<int> &coins, int i, int a)
    {
        if (a == 0)
        {
            return 1;
        }
        if (i >= coins.size())
        {
            return 0;
        }

        int res = 0;
        if (a >= coins[i])
        {
            res = dfs(coins, i + 1, a);
            res += dfs(coins, i, a - coins[i]);
        }
        return res;
    }
};

/* ----------------------------------------------------- */

// This is the solution with DP
class DPSolution
{
public:
    int change(int amount, vector<int> &coins)
    {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return dfs(coins, 0, amount, dp);
    }

    int dfs(const vector<int> coins, int i, int a, vector<vector<int>> &dp)
    {
        if (a == 0)
        {
            return 1;
        }

        if (i >= coins.size())
        {
            return 0;
        }

        if (dp[i][a] != -1)
        {
            return dp[i][a];
        }

        int ans = 0;
        if (a >= coins[i])
        {
            ans = dfs(coins, i + 1, a, dp);
            ans += dfs(coins, i, a - coins[i], dp);
        }
        dp[i][a] = ans;
        return ans;
    }
};

int main()
{
    BruteForceSolution obj;

    int amount = 4;
    vector<int> coins = {1, 2, 3};
    cout << obj.change(amount, coins) << endl;
}