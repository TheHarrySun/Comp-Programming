/* ----------------------------------------------------- */
/* MedianofTwoSortedArrays.cpp                           */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Median of Two Sorted Arrays */
/* Difficulty: Hard */

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <limits>
#include <unordered_set>
#include <stack>
#include <set>
#include <string>

using namespace std;

/* ----------------------------------------------------- */

// This solution is not efficient enough, we want O(log(n + m)), but this
// solution is O(n + m)
class LessEfficientSolution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int total_size = nums1.size() + nums2.size();
        bool even = total_size % 2 == 0;
        int half = total_size / 2;
        int r = 0;
        int l = 0;
        int ans;
        for (int i = 0; i < half; i++)
        {
            if (l == nums1.size())
            {
                ans = nums2[r];
                r++;
            }
            else if (r == nums2.size())
            {
                ans = nums1[l];
                l++;
            }
            else if (nums1[l] <= nums2[r])
            {
                ans = nums1[l];
                l++;
            }
            else
            {
                ans = nums2[r];
                r++;
            }
        }
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        if (even)
        {
            return (ans + min(nums1[l], nums2[r])) / 2.0;
        }
        else
        {
            return min(nums1[l], nums2[r]);
        }
    }
};

// more efficient solution to achieve O(log(n+m))
class MoreEfficientSolution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> &A = nums1;
        vector<int> &B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;

        if (A.size() > B.size())
        {
            swap(A, B);
        }

        int l = 0;
        int r = A.size();
        while (l <= r)
        {
            int i = (l + r) / 2;
            int j = half - i;

            int Aleft = i > 0 ? A[i - 1] : INT_MIN;
            int Aright = i < A.size() ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j - 1] : INT_MIN;
            int Bright = j < B.size() ? B[j] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright)
            {
                if (total % 2)
                {
                    return max(Aleft, Bleft);
                }
                return (min(Aright, Bright) + max(Aleft, Bleft)) / 2.0;
            }
            else if (Aleft > Bright)
            {
                r = i - 1;
            }
            else
            {
                l = i + 1;
            }
        }
        return -1;
    }
};