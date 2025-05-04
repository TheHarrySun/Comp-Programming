/* ----------------------------------------------------- */
/* LowestAncestorBTree.cpp                               */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Lowest Common Ancestor in Binary Search Tree */
/* Difficulty: Medium */

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int val = root->val;
        if (val == q->val)
        {
            return q;
        }
        if (val == p->val)
        {
            return p;
        }
        if ((val < q->val && val > p->val) || (val > q->val && val < p->val))
        {
            return root;
        }

        if (val < q->val && val < p->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (val > q->val && val > p->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};