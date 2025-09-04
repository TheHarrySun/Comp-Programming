/*
https://codeforces.com/group/hNnRWqFua0/contest/557508/problem/E

Solved? YES
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <unordered_map>

typedef long long ll;

using namespace std;

int main()
{
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        vector<ll> array(n);
        for (ll j = 0; j < n; j++)
        {
            cin >> array[j];
        }
        ll lower = 0;
        ll upper = LONG_LONG_MAX;
        for (ll j = 0; j + 1 < n; j++)
        {
            if (array[j] > array[j + 1])
            {
                lower = max((array[j] + array[j + 1] + 1) / 2, lower);
            }
            if (array[j] < array[j + 1])
            {
                upper = min(upper, (array[j] + array[j + 1]) / 2);
            }
        }
        if (lower > upper)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << lower << endl;
        }
    }
}