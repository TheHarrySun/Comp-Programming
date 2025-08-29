/*
https://codeforces.com/group/hNnRWqFua0/contest/557508/problem/C

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
    ll x, y;
    cin >> x >> y;

    vector<bool> hit(n, false);
    vector<pair<ll, ll>> troopers(n);
    for (ll i = 0; i < n; i++)
    {
        ll newx, newy;
        cin >> newx >> newy;
        troopers[i] = make_pair(newx, newy);
    }

    ll index = 0;
    ll ans = 0;
    while (index < n)
    {
        if (hit[index])
        {
            index++;
            continue;
        }
        pair<ll, ll> curr = troopers[index];
        bool vertical = false;
        if (curr.first == x)
        {
            vertical = true;
        }
        ll xdiff = curr.first - x;
        ll ydiff = curr.second - y;
        for (ll i = index; i < n; i++)
        {
            if (hit[i])
            {
                continue;
            }
            pair<ll, ll> troop = troopers[i];
            if (vertical)
            {
                hit[i] = (troop.first == curr.first);
                continue;
            }
            ll remainder = (troop.first - x) * ydiff % xdiff;
            if (remainder == 0 && (troop.first - x) * ydiff / xdiff == troop.second - y)
            {
                hit[i] = true;
            }
        }
        ans++;
        index++;
    }
    cout << ans << endl;
}