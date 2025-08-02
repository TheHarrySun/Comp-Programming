/* ----------------------------------------------------- */
/* BTreeLevelOrder.cpp                                   */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Binary Tree Level Order Traversal */
/* Difficulty: Medium */

#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<pair<TreeNode *, int>> order;
        order.push(make_pair(root, 0));
        while (!order.empty())
        {
            pair<TreeNode *, int> curr = order.front();
            order.pop();
            if (curr.first->left != nullptr)
            {
                order.push(make_pair(curr.first->left, curr.second + 1));
            }
            if (curr.first->right != nullptr)
            {
                order.push(make_pair(curr.first->right, curr.second + 1));
            }
            if (res.size() < curr.second + 1)
            {
                vector<int> col;
                res.push_back(col);
            }
            res[curr.second].push_back(curr.first->val);
        }
        return res;
    }
};