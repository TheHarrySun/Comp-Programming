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
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> nodes;
        dfs(nodes, root);
        return nodes[k - 1];
    }

private:
    void dfs(vector<int> &nodes, TreeNode *root)
    {
        if (root->left == nullptr)
        {
            nodes.push_back(root->val);
            if (root->right != nullptr)
                dfs(nodes, root->right);
            return;
        }
        dfs(nodes, root->left);
        nodes.push_back(root->val);
        if (root->right != nullptr)
            dfs(nodes, root->right);
    }
};