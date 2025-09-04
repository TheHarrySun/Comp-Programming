/*
https://codeforces.com/group/hNnRWqFua0/contest/557508/problem/D

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
        unordered_map<string, ll> countXY;
        unordered_map<string, ll> countXZ;
        unordered_map<string, ll> countYZ;
        unordered_map<string, ll> countXYZ;
        ll ans = 0;
        for (ll j = 0; j + 2 < n; j++)
        {
            ll x = array[j], y = array[j + 1], z = array[j + 2];
            string xykey = to_string(x) + " " + to_string(y);
            string xzkey = to_string(x) + " " + to_string(z);
            string yzkey = to_string(y) + " " + to_string(z);
            string xyzkey = to_string(x) + " " + to_string(y) + " " + to_string(z);

            ans += countXY[xykey] + countXZ[xzkey] + countYZ[yzkey] - 3 * countXYZ[xyzkey];

            countXY[xykey]++;
            countXZ[xzkey]++;
            countYZ[yzkey]++;
            countXYZ[xyzkey]++;
        }
        cout << ans << endl;
    }
}