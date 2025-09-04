/*
Problem Link: https://codeforces.com/group/hNnRWqFua0/contest/553384/problem/D

Description:
You are leading a kayaking trip with a mixed group of participants in the
Stockholm archipelago, but as you are about to begin your final stretch
back to the mainland you notice a storm on the horizon. You had better
paddle as fast as you can to make sure you do not get trapped on one of
the islands. Of course, you cannot leave anyone behind, so your speed
will be determined by the slowest kayak. Time to start thinking; How
should you distribute the participants among the kayaks to maximize your
chance of reaching the mainland safely?

The kayaks are of different types and have different amounts of packing,
so some are more easily paddled than others. This is captured by a speed
factor c that you have already figured out for each kayak. The final
speed v of a kayak, however, is also determined by the strengths s1 and
s2 of the two people in the kayak, by the relation v=c(s1+s2). In your
group you have some beginners with a kayaking strength of sb, a number
of normal participants with strength sn and some quite experienced
strong kayakers with strength se.

Input
The first line of input contains three non-negative integers b, n, and e,
denoting the number of beginners, normal participants, and experienced
kayakers, respectively. The total number of participants, b+n+e, will be
even, at least 2, and no more than 100,000. This is followed by a line
with three integers sb, sn, and se, giving the strengths of the
corresponding participants (1≤sb<sn<se≤1000). The third and final line
contains m=(b+n+e)/2 integers c1,…,cm (1≤ci≤100000 for each i), each giving
the speed factor of one kayak.

Output
Output a single integer, the maximum speed that the slowest kayak can
get by distributing the participants two in each kayak.
*/

/*
Solved? Yes
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool check(ll pos, ll b, ll n, ll e, ll sb, ll sn, ll se, vector<ll> c);

int main(void)
{
    ll b, n, e;
    cin >> b >> n >> e;
    ll sb, sn, se;
    cin >> sb >> sn >> se;

    ll m = (b + n + e) / 2;
    vector<ll> c(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> c[i];
    }

    sort(c.begin(), c.end());

    ll maxSpeed = c[m - 1] * 2 * se;
    ll pos = 0;
    for (ll a = maxSpeed; a >= 1; a /= 2)
    {
        while (check(pos + a, b, n, e, sb, sn, se, c))
        {
            pos = pos + a;
        }
    }
    cout << pos << endl;
}

bool check(ll pos, ll b, ll n, ll e, ll sb, ll sn, ll se, vector<ll> c)
{
    for (ll factor : c)
    {
        if (b >= 2 && 2 * factor * sb >= pos)
        {
            b -= 2;
            continue;
        }
        if (b >= 1 && n >= 1 && factor * (sb + sn) >= pos)
        {
            b -= 1;
            n -= 1;
            continue;
        }
        if (sb + se < 2 * sn)
        {
            if (b >= 1 && e >= 1 && factor * (sb + se) >= pos)
            {
                b -= 1;
                e -= 1;
                continue;
            }
            if (n >= 2 && 2 * factor * sn >= pos)
            {
                n -= 2;
                continue;
            }
        }
        else
        {
            if (n >= 2 && 2 * factor * sn >= pos)
            {
                n -= 2;
                continue;
            }
            if (b >= 1 && e >= 1 && factor * (sb + se) >= pos)
            {
                b -= 1;
                e -= 1;
                continue;
            }
        }
        if (e >= 1 && n >= 1 && factor * (sn + se) >= pos)
        {
            n -= 1;
            e -= 1;
            continue;
        }
        if (e >= 2 && 2 * factor * se >= pos)
        {
            e -= 2;
            continue;
        }
        return false;
    }
    return true;
}