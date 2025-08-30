/*
https://codeforces.com/group/hNnRWqFua0/contest/561424/problem/B

Solved? Yes
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
        ll n, k;
        cin >> n >> k;

        ll ans;
        ll black = 0;
        ll white = 0;
        ll first = 0;
        ll last = k - 1;
        string seq = "";
        for (int j = 0; j < n; j++)
        {
            char temp;
            cin >> temp;
            if (j <= k - 1)
            {
                if (temp == 'B')
                    black++;
                else if (temp == 'W')
                    white++;
            }
            seq += temp;
        }
        ans = white;

        while (last < n - 1)
        {
            if (seq[first] == 'B')
            {
                black--;
            }
            else
            {
                white--;
            }
            first++;
            last++;
            if (seq[last] == 'B')
            {
                black++;
            }
            else
            {
                white++;
            }
            ans = min(white, ans);
        }
        cout << ans << endl;
    }
}