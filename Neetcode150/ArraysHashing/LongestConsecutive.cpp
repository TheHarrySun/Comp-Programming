/* ----------------------------------------------------- */
/* LongestConsecutive.cpp                                */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Longest Consecutive Sequence */
/* Difficulty: Medium */

#include <vector>
#include <unordered_set>

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> freq(nums.begin(), nums.end());
        int ans = 0;
        vector<int> starts;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq.count(nums[i] - 1))
            {
                int dist = 1;
                while (freq.find(nums[i] + dist) != freq.end())
                {
                    dist++;
                }
                ans = max(dist, ans);
            }
        }
        return ans;
    }
};
