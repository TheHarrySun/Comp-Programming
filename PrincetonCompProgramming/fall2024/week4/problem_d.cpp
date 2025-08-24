/*
Problem Link: https://codeforces.com/group/hNnRWqFua0/contest/555432/problem/D
*/

/*
Solved? YES
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>

typedef long long ll;

using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    queue<ll> q;
    unordered_set<ll> convos;
    for (ll i = 0; i < n; i++)
    {
        ll id;
        cin >> id;
        if (convos.find(id) != convos.end())
        {
            continue;
        }
        q.push(id);
        convos.insert(id);
        if (q.size() > k)
        {
            ll remove = q.front();
            q.pop();
            convos.erase(remove);
        }
    }
    cout << q.size() << endl;
    vector<ll> ans;
    while (!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }

    for (int i = ans.size() - 1; i > 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << ans[0] << endl;
}