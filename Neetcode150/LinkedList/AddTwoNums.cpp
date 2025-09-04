/* ----------------------------------------------------- */
/* AddTwoNums.cpp                                        */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Add Two Numbers */
/* Difficulty: Medium */

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *list1 = l1;
        ListNode *list2 = l2;
        int carry = 0;
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;

        while (list1 != nullptr || list2 != nullptr)
        {
            temp->next = new ListNode(carry);
            carry = 0;
            temp = temp->next;
            int sum = temp->val;
            if (list1 != nullptr)
            {
                sum += list1->val;
            }
            if (list2 != nullptr)
            {
                sum += list2->val;
            }
            if (sum > 9)
            {
                carry = 1;
            }
            temp->val = sum % 10;
            if (list1 != nullptr)
            {
                list1 = list1->next;
            }
            if (list2 != nullptr)
            {
                list2 = list2->next;
            }
        }
        if (carry != 0)
        {
            temp->next = new ListNode(carry);
        }
        ListNode *res = ans->next;
        delete ans;
        return res;
    }
};
