/*
Problem Link: https://codeforces.com/group/hNnRWqFua0/contest/551614/problem/C

Description:
It's 2050, and the typical Princeton undergrad now takes n classes a
semester. Each class is given an interval [a,b], which means that
class has a lecture starting at a hours and ending at b  hours, where
a and b are positive integers such that a < b (note that they can
be larger than 24; it's 2050 after all). Because it's impossible to
schedule so many classes, there might be overlap between classes.

You are given the collection of classes of a certain student. Your
goal is to output the total amount of hours of work, i.e., how many
hours have at least one class going on.

Input
The first line of the input contains one integer n (1 ≤ n ≤ 10^5).

Then follow n lines, each containing two integers separated by spaces,
representing a class interval. Each interval [a,b] satisfies
1 ≤ a < b ≤ 10^9.

Output
The output should contain a single integer, the number of hours of work.
*/

/*
Solved? Yes!
*/

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