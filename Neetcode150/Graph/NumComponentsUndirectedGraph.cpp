/* ----------------------------------------------------- */
/* NumComponentsUndirectedGraph.cpp                      */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Number of Connected Components in an Undirected Graph */
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
    int countComponents(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adjMap;

        for (auto edge : edges)
        {
            adjMap[edge[0]].push_back(edge[1]);
            adjMap[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        unordered_set<int> visited;
        for (int i = 0; i < n; i++)
        {
            if (visited.count(i))
            {
                continue;
            }
            else
            {
                res += 1;
                dfs(i, visited, adjMap);
            }
        }
        return res;
    }

    void dfs(int course, unordered_set<int> &visited, unordered_map<int, vector<int>> &adjMap)
    {
        visited.insert(course);
        for (int i : adjMap[course])
        {
            if (!visited.count(i))
            {
                dfs(i, visited, adjMap);
            }
        }
    }
};