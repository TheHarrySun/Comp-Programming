/* ----------------------------------------------------- */
/* RemoveNode.cpp                                        */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Remove Node From End of Linked List */
/* Difficulty: Medium */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* First solution is two iterations, one iteration for determining length
and second iteration to find the spot to remove the element. */
class Solution1
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = 0;
        ListNode *begin = head;
        while (begin != nullptr)
        {
            size += 1;
            begin = begin->next;
        }
        int remove = size - n;
        if (remove == 0)
        {
            return head->next;
        }
        ListNode *prev = head;
        ListNode *curr = head->next;
        for (int i = 1; i < remove; i++)
        {
            prev = prev->next;
            curr = curr->next;
        }
        prev->next = curr->next;
        return head;
    }
};

/* Second solution is with two pointers. The first pointer is
n steps in front of the second pointer. Then you keep incrementing
both pointers until the pointer in front reaches nullptr. The
second pointer would be at a position to remove the desired entry. */

class Solution2
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *left = dummy;
        ListNode *right = head;
        while (n > 0)
        {
            right = right->next;
            n--;
        }
        while (right != nullptr)
        {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy->next;
    }
};