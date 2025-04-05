#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ll num;
    scanf("%lld", &num);

    vector<ll> cards(num);
    for (ll i = 0; i < num; i++)
    {
        scanf("%lld", &cards[i]);
    }

    sort(cards.begin(), cards.end());

    ll ans = 1;
    for (ll i = 1; i < num; i++)
    {
        if (cards[i] != cards[i - 1])
        {
            ans += 1;
        }
    }
    printf("%lld\n", ans);
}