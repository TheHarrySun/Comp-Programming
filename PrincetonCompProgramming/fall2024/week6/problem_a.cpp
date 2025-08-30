/*
https://codeforces.com/group/hNnRWqFua0/contest/561424/problem/A

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
        ll ans = 1;
        while (n > 0)
        {
            ans *= 2;
            n--;
        }
        cout << ans - 1 << endl;
    }
}