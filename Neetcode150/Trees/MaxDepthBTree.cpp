/* ----------------------------------------------------- */
/* MaxDepthBTree.cpp                                     */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Maximum Depth of Binary Tree */
/* Difficulty: Easy */

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

class OriginalSolution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        queue<pair<TreeNode *, int>> queue;
        queue.push(make_pair(root, 1));
        int ans = 0;
        while (!queue.empty())
        {
            pair<TreeNode *, int> curr = queue.front();
            TreeNode *node = curr.first;
            int depth = curr.second;
            if (node != nullptr && depth > ans)
            {
                ans = depth;
            }
            queue.pop();
            if (node->left != nullptr)
                queue.push(make_pair(node->left, depth + 1));
            if (node->right != nullptr)
                queue.push(make_pair(node->right, depth + 1));
        }
        return ans;
    }
};

/* ----------------------------------------------------- */

class RecursiveSolution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};