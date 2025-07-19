/* ----------------------------------------------------- */
/* TaskScheduler.cpp                                     */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Task Scheduler */
/* Difficulty: Medium */

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/* ----------------------------------------------------- */

/*
Solution explanation:
The general algorithm will be to do the following
1. Count up the number of each task and add them to a max-heap.
2. Execute the task with the highest frequency, and remove that task from the heap.
3. Keep executing the task with the highest frequency until you don't have any more tasks.
4. Return the total time that it takes.
*/
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> counts(26, 0);
        for (char task : tasks)
        {
            counts[task - 'A']++;
        }

        priority_queue<int> maxheap;
        for (int count : counts)
        {
            if (count > 0)
            {
                maxheap.push(count);
            }
        }

        /* the key is the count of a task, and the value is time */
        queue<pair<int, int>> q;
        int totaltime = 0;
        while (!maxheap.empty() || !q.empty())
        {
            totaltime += 1;

            if (maxheap.empty())
            {
                totaltime = q.front().second;
            }
            else
            {
                int count = maxheap.top() - 1;
                maxheap.pop();
                if (count > 0)
                {
                    q.push({count, totaltime + n});
                }
            }

            if (!q.empty() && q.front().second == totaltime)
            {
                maxheap.push(q.front().first);
                q.pop();
            }
        }
        return totaltime;
    }
};