/* ----------------------------------------------------- */
/* FindDuplicate.cpp                                     */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Find the Duplicate Number */
/* Difficulty: Medium */

#include <iostream>
#include <vector>

using namespace std;

class NegativeMarkingSolution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
            {
                return abs(nums[i]);
            }
            else
            {
                nums[index] *= -1;
            }
        }
        return 0;
    }
};

class FloydsSolution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
            {
                break;
            }
        }

        int slow2 = 0;
        while (true)
        {
            if (slow == slow2)
            {
                break;
            }
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};