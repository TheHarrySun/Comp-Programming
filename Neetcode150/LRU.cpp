/* ----------------------------------------------------- */
/* LRU.cpp                                               */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: LRU Cache */
/* Difficulty: Medium */

#include <unordered_map>

using namespace std;

class Node
{
public:
    int key;
    int val;
    Node *next;
    Node *prev;

    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache
{
private:
    unordered_map<int, Node *> keyval_pairs;
    int capacity;
    Node *recent;
    Node *old;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->recent = nullptr;
        this->old = nullptr;
    }

    int get(int key)
    {
        Node return -1;
    }

    void put(int key, int value)
    {
    }
}