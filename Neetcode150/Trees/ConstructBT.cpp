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
#include <unordered_map>

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
        for (int i = 0; i < inorder.size(); i++)
        {
            indices[inorder[i]] = i;
        }
        return buildSubtree(preorder, 0, inorder.size() - 1);
    }

private:
    int pre_idx = 0;
    unordered_map<int, int> indices;
    TreeNode *buildSubtree(vector<int> preorder, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }
        int root_val = preorder[pre_idx++];
        TreeNode *root = new TreeNode(root_val);
        int mid = indices[root_val];
        root->left = buildSubtree(preorder, l, mid - 1);
        root->right = buildSubtree(preorder, mid + 1, r);
        return root;
    }
};