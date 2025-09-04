/* ----------------------------------------------------- */
/* Search2DMatrix.cpp                                           */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Search a 2D Matrix */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int top = 0;
        int bottom = rows - 1;

        // sorting through the rows to find which one has our value
        while (top <= bottom)
        {
            int mid = (top + bottom) / 2;
            if (target > matrix[mid][cols - 1])
            {
                top = mid + 1;
            }
            else if (target < matrix[mid][0])
            {
                bottom = mid - 1;
            }
            else
            {
                break;
            }
        }

        // if the row was never found, return false
        if (!(top <= bottom))
        {
            return false;
        }

        // then binary search through the row's elements
        int row = (top + bottom) / 2;
        int l = 0, r = cols - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (target > matrix[row][m])
            {
                l = m + 1;
            }
            else if (target < matrix[row][m])
            {
                r = m - 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> matrix = {{1, 2, 4, 8}, {10, 11, 12, 13}, {14, 20, 30, 40}};
    int target = 20;
    cout << obj.searchMatrix(matrix, target) << endl;
}