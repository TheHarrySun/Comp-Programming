/* ----------------------------------------------------- */
/* KClosestPoints.cpp                                    */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: K Closest Points to Origin */
/* Difficulty: Medium */

#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

/* ----------------------------------------------------- */

class MySolution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        unordered_map<double, vector<vector<int>>> mapping;
        priority_queue<double, vector<double>, greater<double>> minheap;
        for (vector<int> point : points)
        {
            double dist = point[0] * point[0] + point[1] * point[1];
            mapping[dist].push_back(point);
            minheap.push(dist);
        }
        vector<vector<int>> ans(k);
        for (int i = 0; i < k; i++)
        {
            int closest = minheap.top();
            minheap.pop();
            ans[i] = mapping[closest][0];
            mapping[closest].erase(mapping[closest].begin());
        }
        return ans;
    }
};

class ActuallyEfficientSolution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, pair<int, int>>> maxheap;
        for (vector<int> point : points)
        {
            int dist = point[0] * point[0] + point[1] * point[1];
            maxheap.push({dist, {point[0], point[1]}});
            if (maxheap.size() > k)
            {
                maxheap.pop();
            }
        }
        vector<vector<int>> ans;
        while (!maxheap.empty())
        {
            ans.push_back({maxheap.top().second.first, maxheap.top().second.second});
            maxheap.pop();
        }
        return ans;
    }
};