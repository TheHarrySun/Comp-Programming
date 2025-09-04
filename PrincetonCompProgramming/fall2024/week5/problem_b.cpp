/*
https://codeforces.com/group/hNnRWqFua0/contest/557508/problem/B

Solved? YES
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <stack>

typedef long long ll;

using namespace std;

int main()
{
    ll n;
    cin >> n;

    stack<char> s;

    for (int i = 0; i < n; i++)
    {
        char curr;
        cin >> curr;
        if (s.empty())
        {
            s.push(curr);
            continue;
        }
        if (curr == '0' && s.top() == '1')
        {
            s.pop();
        }
        else if (curr == '1' && s.top() == '0')
        {
            s.pop();
        }
        else
        {
            s.push(curr);
        }
    }
    cout << s.size() << endl;
}