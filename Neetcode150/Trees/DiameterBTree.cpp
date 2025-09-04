/* ----------------------------------------------------- */
/* DiameterBTree.cpp                                     */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Diameter of Binary Tree */
/* Difficulty: Easy */

#include <algorithm>

using namespace std;

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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int res = 0;
        dfs(root, res);
        return res;
    }

private:
    int dfs(TreeNode *node, int &res)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int left = dfs(node->left, res);
        int right = dfs(node->right, res);
        res = max(res, left + right);

        return 1 + max(left, right);
    }
};