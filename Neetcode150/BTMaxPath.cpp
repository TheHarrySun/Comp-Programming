/* ----------------------------------------------------- */
/* BTMaxPath.cpp                                         */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Binary Tree Maximum Path Sum */
/* Difficulty: Hard */

#include <iostream>
#include <vector>
#include <algorithm>
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
private:
    int totalmax = INT_MIN;
    int getMax(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = getMax(root->left);
        int right = getMax(root->right);
        return max(root->val + max(left, right), 0);
    }

    void getPath(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        totalmax = max(totalmax, root->val + getMax(root->left) + getMax(root->right));
        getPath(root->left);
        getPath(root->right);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        getPath(root);
        return totalmax;
    }
};