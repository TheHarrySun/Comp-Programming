/*
Problem Link: https://codeforces.com/group/hNnRWqFua0/contest/555432/problem/B
*/

/*
Solved? YES
*/

#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

unordered_set<string> take_inputs(int n)
{
    unordered_set<string> res;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        res.insert(word);
    }
    return res;
}

int check(unordered_set<string> p1, unordered_set<string> p2, unordered_set<string> p3)
{
    int points = 0;
    for (string it : p1)
    {
        int num = 1;
        if (p2.find(it) != p2.end())
        {
            num += 1;
        }
        if (p3.find(it) != p3.end())
        {
            num += 1;
        }
        if (num == 1)
        {
            points += 3;
        }
        else if (num == 2)
        {
            points += 1;
        }
    }
    return points;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        unordered_set<string> p1 = take_inputs(n);
        unordered_set<string> p2 = take_inputs(n);
        unordered_set<string> p3 = take_inputs(n);
        int ans[3];
        cout << check(p1, p2, p3) << " " << check(p2, p1, p3) << " " << check(p3, p1, p2) << endl;
    }
}