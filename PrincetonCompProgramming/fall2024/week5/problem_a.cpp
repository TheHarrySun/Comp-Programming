/*
https://codeforces.com/group/hNnRWqFua0/contest/557508/problem/A

Solved? YES
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

typedef long long ll;

using namespace std;

int main()
{
    ll n;
    cin >> n;

    vector<ll> contests(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> contests[i];
    }
    sort(contests.begin(), contests.end());
    int day = 0;
    int index = 0;
    while (index < n)
    {
        day++;
        index++;
        while (index < n && contests[index] < day + 1)
        {
            index++;
        }
    }
    cout << day << endl;
}