/* ----------------------------------------------------- */
/* RectInHist.cpp                                        */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Largest Rectangle in Histogram */
/* Difficulty: Hard */

#include <vector>
#include <unordered_set>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<pair<int, int>> bounds(heights.size(), {0, n - 1});
        stack<pair<int, int>> left;
        stack<pair<int, int>> right;
        for (int i = n - 1; i >= 0; i--)
        {
            if (left.empty())
            {
                left.push({heights[i], i});
            }
            else
            {
                while (!left.empty() && left.top().first > heights[i])
                {
                    bounds[left.top().second].first = i + 1;
                    left.pop();
                }
                left.push({heights[i], i});
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (right.empty())
            {
                right.push({heights[i], i});
            }
            else
            {
                while (!right.empty() && right.top().first > heights[i])
                {
                    bounds[right.top().second].second = i - 1;
                    right.pop();
                }
                right.push({heights[i], i});
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int area = heights[i] * (bounds[i].second - bounds[i].first + 1);
            ans = max(area, ans);
        }
        return ans;
    }
};
