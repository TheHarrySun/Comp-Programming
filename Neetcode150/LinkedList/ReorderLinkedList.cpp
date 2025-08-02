/* ----------------------------------------------------- */
/* ReorderLinkedList.cpp                                 */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Reorder Linked List */
/* Difficulty: Medium */

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
Overall Strategy:
Use fast and slow pointers to find the midway point. Split the
linked list into the first half and the second half. Reverse the
second half linked list. Then, merge the two together.
*/

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        ListNode *fast = head->next;
        ListNode *slow = head;
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            return;
        }

        /* find the second half of the linked list */
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        /* reverse second half of list */
        ListNode *second = slow->next;
        ListNode *prev = slow->next = nullptr;
        while (second != nullptr)
        {
            ListNode *temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        /* merge the two lists */
        ListNode *first = head;
        second = prev;
        while (second != nullptr)
        {
            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};
