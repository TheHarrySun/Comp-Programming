/* ----------------------------------------------------- */
/* DailyTemps.cpp                                        */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Daily Temperatures */
/* Difficulty: Medium */

#include <vector>
#include <unordered_set>
#include <stack>
#include <string>

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<pair<int, int>> s;
        vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++)
        {
            int t = temperatures[i];
            while (!s.empty() && s.top().first < t)
            {
                auto pair = s.top();
                s.pop();
                ans[pair.second] = i - pair.second;
            }
            s.push({t, i});
        }
        return ans;
    }
};
