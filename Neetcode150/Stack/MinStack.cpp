/* ----------------------------------------------------- */
/* MinStack.cpp                                          */
/* Author: Harrison Xu                                   */
/* Email: hx2004@princeton.edu                           */
/* ----------------------------------------------------- */

/* LeetCode Problem: Minimum Stack */
/* Difficulty: Medium */

#include <vector>
#include <unordered_set>
#include <stack>
#include <string>

using namespace std;

/* ----------------------------------------------------- */

class MinStack
{
public:
    stack<int> s;
    stack<int> minstack;
    MinStack()
    {
    }

    void push(int val)
    {
        s.push(val);
        int mini = min(val, minstack.empty() ? val : minstack.top());
        minstack.push(mini);
    }

    void pop()
    {
        s.pop();
        minstack.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return minstack.top();
    }
};
