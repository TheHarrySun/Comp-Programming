/* ------------------------------------------------------ */
/* FindMinRotatedArray.cpp                                */
/* Author: Harrison Xu                                    */
/* Email: hx2004@princeton.edu                            */
/* ------------------------------------------------------ */

/* LeetCode Problem: Find Minimum in Rotated Sorted Array */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int ans = nums[0];
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            if (nums[l] < nums[r])
            {
                ans = min(ans, nums[l]);
                break;
            }

            int m = (l + r) / 2;
            ans = min(ans, nums[m]);
            if (nums[m] > nums[r])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {3, 4, 5, 6, 1, 2};
    cout << obj.findMin(nums) << endl;

    nums = {4, 5, 0, 1, 2, 3};
    cout << obj.findMin(nums) << endl;

    nums = {4, 5, 6, 7};
    cout << obj.findMin(nums) << endl;
}