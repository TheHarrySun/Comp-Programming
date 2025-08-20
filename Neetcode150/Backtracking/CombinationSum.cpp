/* ----------------------------------------------------- */
/* CombinationSum.cpp                                    */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Combination Sum */
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
#include <string>

using namespace std;

/* ----------------------------------------------------- */

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        dfs(nums, target, 0, 0, res, temp);
        return res;
    }

private:
    void dfs(vector<int> nums, int target, int curr, int index, vector<vector<int>> &res, vector<int> &temp)
    {
        if (curr == target)
        {
            res.push_back(temp);
            return;
        }
        if (curr > target)
        {
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            dfs(nums, target, curr + nums[i], i, res, temp);
            temp.pop_back();
        }
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {2, 5, 6, 9};
    int target = 9;
    for (auto it : obj.combinationSum(nums, target))
    {
        for (auto num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}