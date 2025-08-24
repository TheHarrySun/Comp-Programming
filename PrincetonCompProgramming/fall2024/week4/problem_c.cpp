/*
Problem Link: https://codeforces.com/group/hNnRWqFua0/contest/555432/problem/C
*/

/*
Solved? YES
*/

#include <queue>
#include <vector>
#include <iostream>

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
        ll s[n];
        ll f[n];
        for (ll j = 0; j < n; j++)
        {
            cin >> s[j];
        }
        for (ll j = 0; j < n; j++)
        {
            cin >> f[j];
        }
        ll curr = s[0];
        for (ll j = 0; j < n - 1; j++)
        {
            cout << f[j] - curr << " ";
            curr = max(f[j], s[j + 1]);
        }
        cout << f[n - 1] - curr << endl;
    }
}