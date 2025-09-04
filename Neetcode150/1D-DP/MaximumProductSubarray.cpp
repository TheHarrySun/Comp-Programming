/* ----------------------------------------------------- */
/* MaximumProductSubarray.cpp                            */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Maximum Product Subarray */
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
    int maxProduct(vector<int> &nums)
    {
        int currMax = 1;
        int currMin = 1;
        int res = 0;
        for (int num : nums)
        {
            res = max(num, res);
        }

        for (int num : nums)
        {
            if (num == 0)
            {
                currMax = 1;
                currMin = 1;
            }
            int temp = num * currMax;
            currMax = max(num * currMax, max(num * currMin, num));
            currMin = min(num * currMax, min(num * currMin, num));
            res = max(res, currMax);
        }
        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {5, -3, 2, 4};
    cout << obj.maxProduct(nums) << endl;
}