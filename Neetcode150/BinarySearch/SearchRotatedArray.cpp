/* ----------------------------------------------------- */
/* SearchRotatedArray.cpp                                */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Search in Rotated Sorted Array */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] == target)
            {
                return m;
            }
            if (nums[m] > nums[r])
            {
                if (target < nums[m] && target >= nums[l])
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else
            {
                if (target > nums[m] && target <= nums[r])
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
        }
        if (nums[(l + r) / 2] == target)
        {
            return (l + r) / 2;
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    int target = 1;
    vector<int> nums = {3, 4, 5, 6, 1, 2};
    cout << obj.search(nums, target) << endl;

    target = 4;
    nums = {3, 5, 6, 0, 1, 2};
    cout << obj.search(nums, target) << endl;
}