#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll> distances(n);
    for (int i = 0; i < n; i++)
    {
        cin >> distances[i];
    }
    sort(distances.begin(), distances.end());

    ll min_dist = numeric_limits<ll>::max();
    for (int i = 0; i < n - 1; i++)
    {
        min_dist = min(min_dist, distances[i + 1] - distances[i]);
    }
    cout << min_dist << endl;
}