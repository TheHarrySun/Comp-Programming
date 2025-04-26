/* ----------------------------------------------------- */
/* MergeKSorted.cpp                                      */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Merge K Sorted Linked Lists */
/* Difficulty: Hard */

#include <vector>
#include <iostream>

using namespace std;

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int length = lists.size();
        ListNode *merged;
        if (length == 0)
        {
            return nullptr;
        }
        if (length == 1)
        {
            return lists[0];
        }
        merged = lists[0];

        for (int i = 1; i < length; i++)
        {
            ListNode *curr1 = merged;
            ListNode *curr2 = lists[i];
            ListNode *dummy = new ListNode(0);
            ListNode *main = dummy;
            while (curr1 != nullptr && curr2 != nullptr)
            {
                ListNode *temp;
                if (curr1->val <= curr2->val)
                {
                    main->next = curr1;
                    curr1 = curr1->next;
                }
                else
                {
                    main->next = curr2;
                    curr2 = curr2->next;
                }
                main = main->next;
            }
            if (curr1 == nullptr)
            {
                main->next = curr2;
            }
            else
            {
                main->next = curr1;
            }
            merged = dummy->next;
        }
        return merged;
    }
};

int main()
{
    Solution obj;
    vector<ListNode *> vector_input;
    ListNode *input = new ListNode(4);
    input = new ListNode(2, input);
    input = new ListNode(1, input);
    vector_input.push_back(input);

    input = new ListNode(5);
    input = new ListNode(3, input);
    input = new ListNode(1, input);
    vector_input.push_back(input);

    input = new ListNode(6);
    input = new ListNode(3, input);
    vector_input.push_back(input);

    ListNode *output = obj.mergeKLists(vector_input);
    while (output != nullptr)
    {
        cout << output->val << endl;
        output = output->next;
    }
}