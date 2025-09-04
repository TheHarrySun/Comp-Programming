/* ----------------------------------------------------- */
/* CoinChange.cpp                                        */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Coin Change */
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
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        vector<int> nums(amount + 1, numeric_limits<int>::max());
        nums[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] < 0 || nums[i - coins[j]] == numeric_limits<int>::max())
                {
                    continue;
                }
                nums[i] = min(nums[i], nums[i - coins[j]] + 1);
            }
        }
        if (nums[amount] == numeric_limits<int>::max())
        {
            return -1;
        }
        return nums[amount];
    }
};

int main()
{
    Solution obj;
    vector<int> coins = {2};
    int amount = 3;
    cout << obj.coinChange(coins, amount) << endl;
}