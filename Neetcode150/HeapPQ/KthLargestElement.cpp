/* ----------------------------------------------------- */
/* KthLargestElement.cpp                                 */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Kth Largest Element in an Array */
/* Difficulty: Medium */

#include <vector>
#include <queue>

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minheap;
        for (int num : nums)
        {
            minheap.push(num);
            if (minheap.size() > k)
            {
                minheap.pop();
            }
        }
        return minheap.top();
    }
};