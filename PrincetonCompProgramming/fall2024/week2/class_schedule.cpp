#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    vector<pair<ll, int>> times;
    ll first;
    ll second;
    ll total = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> first >> second;
        total += second - first;
        times.push_back(make_pair(first, 0));
        times.push_back(make_pair(second, 1));
    }
    sort(times.begin(), times.end());

    ll active = 1;

    for (ll i = 1; i < 2 * n; i++)
    {
        if (active > 1)
        {
            total -= (times[i].first - times[i - 1].first) * (active - 1);
        }
        if (times[i].second == 0)
        {
            active += 1;
        }
        if (times[i].second == 1)
        {
            active -= 1;
        }
    }
    cout << total << endl;
}