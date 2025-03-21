/* ----------------------------------------------------- */
/* ReverseLinkedList.cpp                                 */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Reverse Linked List */
/* Difficulty: Easy */

#include <iostream>
#include <vector>

using namespace std;

/* Definition for singly-linked list */
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;

        while (curr != nullptr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

int main()
{
    Solution obj;
    ListNode node1 = ListNode(3);
    ListNode *head = &node1;
    ListNode *curr = head;
    ListNode node2 = ListNode(2);
    head->next = &node2;
    head = head->next;
    ListNode node3 = ListNode(1);
    head->next = &node3;
    head = head->next;
    ListNode node4 = ListNode(0);
    head->next = &node4;

    ListNode *reversed = obj.reverseList(curr);
    while (reversed != nullptr)
    {
        cout << reversed->val << endl;
        reversed = reversed->next;
    }
    /* Correct output should be 0 1 2 3 */
}