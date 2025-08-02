/* ----------------------------------------------------- */
/* CourseScheduleII.cpp                                  */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Course Schedule II */
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
    unordered_map<int, vector<int>> prereqMap;
    unordered_set<int> visited;
    unordered_set<int> path;
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        for (auto prereq : prerequisites)
        {
            prereqMap[prereq[1]].push_back(prereq[0]);
        }

        stack<int> s;
        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(i, s))
            {
                return vector<int>();
            }
        }

        vector<int> ans;
        for (int i = 0; i < numCourses; i++)
        {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }

    bool dfs(int course, stack<int> &s)
    {
        if (path.count(course))
        {
            return false;
        }
        if (visited.count(course))
        {
            return true;
        }
        path.insert(course);
        visited.insert(course);
        for (int next : prereqMap[course])
        {
            if (!dfs(next, s))
            {
                return false;
            }
        }
        s.push(course);
        path.erase(course);
        return true;
    }
};