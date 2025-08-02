/* ----------------------------------------------------- */
/* ContainsDuplicate.cpp                                 */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Contains Duplicate */

#include <set>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen;
        for (int num : nums)
        {
            if (seen.count(num) == 1)
            {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3, 3};
    vector<int> nums2 = {1, 2, 3, 4};
    Solution obj;
    cout << obj.hasDuplicate(nums1) << endl;
    // should output as 1 for true

    cout << obj.hasDuplicate(nums2) << endl;
    // should output as 0 for false
}