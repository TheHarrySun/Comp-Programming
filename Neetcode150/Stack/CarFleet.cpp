/* ----------------------------------------------------- */
/* CarFleet.cpp                                          */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Car Fleet */
/* Difficulty: Medium */

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
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++)
        {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.rbegin(), pairs.rend());
        stack<double> times;
        for (int i = 0; i < n; i++)
        {
            double time = (target - pairs[i].first) / (1.0 * pairs[i].second);
            if (times.empty())
            {
                times.push(time);
                continue;
            }
            if (time > times.top())
            {
                times.push(time);
            }
        }
        return times.size();
    }
};
