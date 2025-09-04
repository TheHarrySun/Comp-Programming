/* ----------------------------------------------------- */
/* LastStoneWeight.cpp                                   */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Last Stone Weight */
/* Difficulty: Easy */

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> stoneheap;
        for (int stone : stones)
        {
            stoneheap.push(stone);
        }
        while (stoneheap.size() > 1)
        {
            int heavy1 = stoneheap.top();
            stoneheap.pop();
            int heavy2 = stoneheap.top();
            stoneheap.pop();
            if (heavy1 == heavy2)
            {
                continue;
            }
            else
            {
                stoneheap.push(abs(heavy1 - heavy2));
            }
        }
        if (stoneheap.size() == 1)
        {
            return stoneheap.top();
        }
        else
        {
            return 0;
        }
    }
};