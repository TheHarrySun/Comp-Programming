/* ----------------------------------------------------- */
/* ConstructBT.cpp                                       */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Construction Binary Tree from Preorder
and Inorder Traversal */
/* Difficulty: Medium */

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
public:
    TreeNode *buildTree(vector<int> preorder, vector<int> inorder)
    {
    }

private:
    TreeNode *buildSubtree(vector<int> preorder, vector<int> inorder, int preorder_index)
    {
        int index;
        int rootval = preorder[preorder_index];
        for (int i = 0; i < inorder.size(); i++)
        {
            if (rootval == inorder[i])
            {
                index = i;
                break;
            }
        }
        TreeNode *res = new TreeNode(rootval);
        if (index != 0)
        {
            vector<int> left_vector(inorder.begin(), inorder.begin() + index);
            res->left = buildSubtree(preorder, left_vector, preorder_index + 1);
        }
        if (index != inorder.size() - 1)
        {
            vector<int> right_vector(inorder.begin() + index + 1, inorder.end());
            res->right = buildSubtree(preorder, right_vector, preorder_index + 1);
        }
    }
};