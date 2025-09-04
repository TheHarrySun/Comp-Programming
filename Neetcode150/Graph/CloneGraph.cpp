/* ----------------------------------------------------- */
/* CloneGraph.cpp                                        */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Clone Graph */
/* Difficulty: Medium */

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

/* ----------------------------------------------------- */

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
        {
            return nullptr;
        }

        unordered_map<Node *, Node *> oldtoNew;
        oldtoNew[node] = new Node(node->val);
        queue<Node *> q;
        q.push(node);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            vector<Node *> neighbors = curr->neighbors;
            for (int i = 0; i < neighbors.size(); i++)
            {
                Node *currNeighbor = neighbors[i];
                if (oldtoNew.find(currNeighbor) == oldtoNew.end())
                {
                    oldtoNew[currNeighbor] = new Node(currNeighbor->val);
                    q.push(currNeighbor);
                }
                oldtoNew[curr]->neighbors.push_back(oldtoNew[currNeighbor]);
            }
        }

        return oldtoNew[node];
    }
};