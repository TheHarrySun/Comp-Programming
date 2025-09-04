/*
Problem Link: https://codeforces.com/group/hNnRWqFua0/contest/553384/problem/E
*/

/*
Solved? Yes!
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;

bool check(ld time, vector<ld> pos, vector<ld> speed);

int main()
{
    ll n;
    cin >> n;
    vector<ld> pos(n);
    vector<ld> speed(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> pos[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> speed[i];
    }

    ld max_time = 0;
    for (ll i = 0; i < n; i++)
    {
        max_time = max(max_time, pos[i] / speed[i]);
    }

    ld time = max_time;
    for (ld a = max_time; a > 1e-8; a /= 2)
    {
        while (check(time - a, pos, speed))
        {
            time = time - a;
        }
    }
    cout << fixed << setprecision(8) << time << endl;
}

bool check(ld time, vector<ld> pos, vector<ld> speed)
{
    ld left = pos[0] - speed[0] * time;
    ld right = pos[0] + speed[0] * time;

    ll length = pos.size();
    for (ll i = 1; i < pos.size(); i++)
    {
        ld currLeft = pos[i] - speed[i] * time;
        ld currRight = pos[i] + speed[i] * time;
        if (currLeft > right || currRight < left)
        {
            return false;
        }
        left = max(currLeft, left);
        right = min(currRight, right);
    }
    return true;
}