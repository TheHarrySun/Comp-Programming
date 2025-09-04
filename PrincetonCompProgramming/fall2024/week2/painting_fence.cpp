/*
Problem Link: https://codeforces.com/group/hNnRWqFua0/contest/551614/problem/D

Description:
Bizon decided to paint his old fence his favorite color, orange. The
fence is represented as n vertical planks, put in a row. Adjacent
planks have no gap between them. The planks are numbered from the left
to the right starting from one, the i-th plank has the width of 1 meter
and the height of a_i meters.

Bizon bought a brush in the shop, the brush's width is 1 meter. He can
make vertical and horizontal strokes with the brush. During a stroke the
brush's full surface must touch the fence at all the time (see the
samples for the better understanding). What minimum number of strokes
should Bizon do to fully paint the fence? Note that you are allowed to
paint the same area of the fence multiple times.

Input
The first line contains integer n (1 ≤ n ≤ 5000) — the number of fence
planks. The second line contains n space-separated integers a_1, a_2, …,
a_n (1 ≤ a_i ≤ 10^9).

Output
Print a single integer — the minimum number of strokes needed to paint
the whole fence.
*/

/*
Solved? Yes!
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll countBrushes(vector<ll> fences)
{
    ll index = 0;
    ll lowest = fences[0];
    ll size = fences.size();
    if (size == 1)
    {
        if (fences[0] == 0)
        {
            return 0;
        }
        return 1;
    }
    for (ll i = 0; i < size; i++)
    {
        if (fences[i] < lowest)
        {
            lowest = fences[i];
            index = i;
        }
    }
    for (ll i = 0; i < size; i++)
    {
        fences[i] -= lowest;
    }
    if (index == 0)
    {
        vector<ll> sv(fences.begin() + 1, fences.end());
        return min(size, lowest + countBrushes(sv));
    }
    if (index == size - 1)
    {
        vector<ll> sv(fences.begin(), fences.end() - 1);
        return min(size, lowest + countBrushes(sv));
    }
    vector<ll> sv1(fences.begin(), fences.begin() + index);
    vector<ll> sv2(fences.begin() + index + 1, fences.end());

    return min(size, lowest + countBrushes(sv1) + countBrushes(sv2));
}

int main(void)
{
    ll n;
    cin >> n;
    vector<ll> fences(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> fences[i];
    }

    cout << countBrushes(fences) << endl;
}