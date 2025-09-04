/*
Problem Link: https://codeforces.com/group/hNnRWqFua0/contest/553384/problem/C

Description:
It's 2050, and the enrollment at Princeton has grown to t students. This
number is so large that cooking enough food for everyone at the dining
halls is a big challenge. The dining halls employ n cooks, and the ith
worker needs ki minutes to prepare one meal. Your goal is to make t meals
so that everyone can eat.

The cooks can work simultaneously, and you can freely decide their schedule.
What is the shortest time needed to make t meals?

Input
The first input line contains two space separated integers n (1≤n≤2⋅10^5)
and t (1≤t≤10^9) — the number of cooks and meals to make.

The next line contains n space separated integers k1,k2,…,kn (1≤ki≤10^9) —
the time the ith cook needs to make one meal.

Output
Print one integer: the minimum time needed to make t meals.
*/

/*
Solved? Yes!
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool check(ll time, vector<ll> cooks, ll meals)
{
    ll total = 0;
    for (ll cook : cooks)
    {
        total += time / cook;
    }
    if (total >= meals)
    {
        return true;
    }
    return false;
}

int main(void)
{
    ll n;
    ll t;
    cin >> n >> t;
    vector<ll> cooks(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> cooks[i];
    }
    ll fastest = *min_element(cooks.begin(), cooks.end());
    ll max = fastest * t;

    ll ans = max;
    for (ll i = max; i >= 1; i /= 2)
    {
        while (check(ans - i, cooks, t))
        {
            ans = ans - i;
        }
    }
    cout << ans << endl;
}