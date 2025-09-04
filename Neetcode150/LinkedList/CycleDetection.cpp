/* ----------------------------------------------------- */
/* CycleDetection.cpp                                    */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Linked List Cycle Detection */
/* Difficulty: Easy */

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
        {
            return false;
        }
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast != nullptr && slow != nullptr)
        {
            if (fast == slow)
            {
                return true;
            }
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr)
            {
                fast = fast->next;
            }
        }
        return false;
    }
};