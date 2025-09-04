/* ----------------------------------------------------- */
/* ValidBSTree.cpp                                       */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Valid Binary Search Tree */
/* Difficulty: Medium */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

/* ----------------------------------------------------- */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* ----------------------------------------------------- */

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return checkBST(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }

private:
    bool checkBST(TreeNode *root, int bot, int top)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val <= bot || root->val >= top)
        {
            return false;
        }
        return checkBST(root->left, bot, root->val) && checkBST(root->right, root->val, top);
    }
};