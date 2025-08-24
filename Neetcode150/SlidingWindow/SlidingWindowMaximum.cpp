/* ----------------------------------------------------- */
/* SlidingWindowMaximum.cpp                              */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Sliding Window Maximum */
/* Difficulty: Hard */

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

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        int l = 0;
        int r = k - 1;
        for (int i = 0; i <= r; i++)
        {
            pq.push({nums[i], i});
        }
        while (r < nums.size())
        {
            pair<int, int> num = pq.top();
            while (num.second < l)
            {
                pq.pop();
                num = pq.top();
            }
            ans.push_back(num.first);
            l++;
            r++;
            pq.push({nums[r], r});
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 1, 0, 4, 2, 6};
    int k = 3;
    Solution obj;
    vector<int> ans = obj.maxSlidingWindow(nums, k);
    for (int a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
}