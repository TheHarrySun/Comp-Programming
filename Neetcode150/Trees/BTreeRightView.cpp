/* ----------------------------------------------------- */
/* BTreeRightView.cpp                                    */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Binary Tree Right Side View */
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
    vector<int> rightSideView(TreeNode *root)
    {
        TreeNode *temp = root;
        vector<int> res;

        if (root == nullptr)
        {
            return res;
        }

        vector<vector<int>> tree;
        queue<pair<TreeNode *, int>> bfs;

        bfs.push(make_pair(root, 0));
        while (!bfs.empty())
        {
            pair<TreeNode *, int> curr = bfs.front();
            bfs.pop();
            if (curr.first->left != nullptr)
            {
                bfs.push(make_pair(curr.first->left, curr.second + 1));
            }
            if (curr.first->right != nullptr)
            {
                bfs.push(make_pair(curr.first->right, curr.second + 1));
            }
            if (tree.size() < curr.second + 1)
            {
                vector<int> temp;
                tree.push_back(temp);
            }
            tree[curr.second].push_back(curr.first->val);
        }

        for (int i = 0; i < tree.size(); i++)
        {
            vector<int> temp = tree[i];
            res.push_back(*(temp.end() - 1));
        }
        return res;
    }
};