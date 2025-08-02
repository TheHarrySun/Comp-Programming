/* ----------------------------------------------------- */
/* RedundantConnection.cpp                               */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Redundant Connection */
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
    unordered_map<int, vector<int>> edgeMap;
    unordered_set<int> visited;
    int cyclestart;
    unordered_set<int> cyclepath;
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        for (auto edge : edges)
        {
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);
        }

        dfs(1, -1);

        int num_nodes = edges.size();
        for (int i = num_nodes - 1; i >= 0; i--)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if (cyclepath.count(u) && cyclepath.count(v))
            {
                return {u, v};
            }
        }
        return {};
    }

    bool dfs(int node, int par)
    {
        if (visited.count(node))
        {
            cyclestart = node;
            return true;
        }
        visited.insert(node);
        for (int adj : edgeMap[node])
        {
            if (adj == par)
            {
                continue;
            }
            if (dfs(adj, node))
            {
                if (cyclestart != -1)
                {
                    cyclepath.insert(node);
                }
                if (cyclestart == node)
                {
                    cyclestart = -1;
                }
                return true;
            }
        }
        return false;
    }
};