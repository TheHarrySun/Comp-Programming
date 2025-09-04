/*
Problem Link: https://codeforces.com/group/hNnRWqFua0/contest/551614/problem/B

Description:
It's 2050, and there are n students attending these competitive
programming sessions. As such, the logistics of giving away pizza
to everyone have become really hard. After a lot of discussion, the
following process was designed. Each of the n students was assigned
a unique number from 1 to n. Students form a long line sorted by
their number, so student 1 goes first, then 2, and so on.

The pizza has just arrived and students are lining up. However, no one
is following the rules, and the ith student is actually the p_ith in
the line. The unhappiness of student i is given by the number of students
ahead of them in line that should be behind them, so the students j > i
such that p_j < p_i. The total unhappiness of the students is the sum of
all the student unhappinesses. Compute this value.

Input
The first line of the input contains an integer n (1 ≤ n ≤ 10^5).

Then the following line contains n distinct integers between 1 and n,
separated by spaces.

Output
The output should contain a line with a single integer, the total unhappiness.
*/

/*
Solved? Yes!
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll merge(vector<ll> &positions, ll left, ll right);

int main()
{
    ll n;
    cin >> n;
    vector<ll> positions(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> positions[i];
    }
    ll output = merge(positions, 0, n - 1);
    cout << output << endl;
}

ll merge(vector<ll> &positions, ll left, ll right)
{
    if (left >= right)
        return 0;

    ll mid = left + (right - left) / 2;
    ll output = 0;
    output += merge(positions, left, mid);
    output += merge(positions, mid + 1, right);

    ll n1 = mid - left + 1;
    ll n2 = right - mid;

    vector<ll> L(n1), R(n2);

    for (ll i = 0; i < n1; i++)
    {
        L[i] = positions[left + i];
    }
    for (ll j = 0; j < n2; j++)
    {
        R[j] = positions[mid + 1 + j];
    }
    ll i = 0, j = 0;
    ll k = left;
    ll inversions = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            positions[k] = L[i];
            i++;
            output += inversions;
        }
        else
        {
            positions[k] = R[j];
            j++;
            inversions++;
        }
        k++;
    }
    while (i < n1)
    {
        positions[k] = L[i];
        i++;
        k++;
        output += inversions;
    }
    while (j < n2)
    {
        positions[k] = R[j];
        j++;
        k++;
    }
    return output;
}